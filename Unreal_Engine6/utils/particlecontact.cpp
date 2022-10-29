#include "particlecontact.h"

ParticleContact::ParticleContact()
{

}

ParticleContact::ParticleContact(Particles *p1, Vector3D normal, float restitution){
    _particles[0] = p1;
    _particles[1] = nullptr;
    _restitution = restitution;
    _normal = normal;
}

ParticleContact::ParticleContact(Particles *p1, Particles *p2, float restitution){
    _particles[0] = p1;
    _particles[1] = p2;
    _restitution = restitution;

    Vector3D distance = (*p1->getPosition() - *p2->getPosition());
    _normal = distance.normalize();
}


float ParticleContact::calculateSeparationVelocity(){
    Vector3D position1 = *_particles[0]->getPosition();
    Vector3D position2 = *_particles[1]->getPosition();
    return (position1 - position2).scalarProduct((position1 - position2).normalize());
}

void ParticleContact::resolveVelocity(){
    Vector3D vrel = *_particles[0]->getInitialVelocity() - *_particles[1]->getInitialVelocity();
    float k = ((_restitution + 1)*(vrel.scalarProduct(_normal)))/(_particles[0]->getInverseMass()+ _particles[1]->getInverseMass());
    Vector3D newVelocity1 = Vector3D(*_particles[0]->getInitialVelocity());
    newVelocity1 = newVelocity1 - _normal * (k*_particles[0]->getInverseMass());
    _particles[0]->setVelocity(&newVelocity1);
    Vector3D newVelocity2 = Vector3D(*_particles[1]->getInitialVelocity());
    newVelocity2 = newVelocity2 - _normal * (k*_particles[1]->getInverseMass());
    _particles[1]->setVelocity(&newVelocity2);
}

void ParticleContact::resolveInterpenetration(){
    if(_particles[1] == nullptr){
        Vector3D newPosition = *_particles[0]->getPosition();
        newPosition = _normal * _penetration + newPosition;
        _particles[0]->setPosition(&newPosition);
        return;
    }
    float mass1 = 1/_particles[0]->getInverseMass();
    float mass2 = 1/_particles[1]->getInverseMass();
    Vector3D newPosition1 = *_particles[0]->getPosition();
    newPosition1 = _normal * (mass2/(mass1+mass2) * _penetration) + newPosition1;
    _particles[0]->setPosition(&newPosition1);

    Vector3D newPosition2 = *_particles[1]->getPosition();
    newPosition1 = _normal * (-mass1/(mass1+mass2) * _penetration) + newPosition1;
    _particles[1]->setPosition(&newPosition2);
}

void ParticleContact::resolve(float duration){
    this->resolveInterpenetration();
    this->resolveVelocity();
}
