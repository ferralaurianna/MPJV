#include "particlecontact.h"

ParticleContact::ParticleContact(Particles *p1, Vector3D normal, float restitution, float penetration){
    _particles[0] = p1;
    _particles[1] = nullptr;
    _restitution = restitution;
    _penetration = penetration;
    _normal = normal;
}

ParticleContact::ParticleContact(Particles *p1, Particles *p2, float restitution){
    _particles[0] = p1;
    _particles[1] = p2;

    Vector3D distance = (*p1->getPosition() - *p2->getPosition());
    if(restitution>0)
    {
        _restitution = restitution;
        _normal = distance.normalize();
    }
    else
    {
        _restitution = -restitution;
        _normal = -(distance.normalize());
    }
    _penetration = (_particles[0]->getRadius() + _particles[1]->getRadius() - distance.norm()) / 2;
    if (_penetration < 0){
        _penetration = 0;
    }
}


float ParticleContact::calculateSeparationVelocity(){
    Vector3D position1 = *_particles[0]->getPosition();
    Vector3D position2 = *_particles[1]->getPosition();
    return (position1 - position2).scalarProduct((position1 - position2).normalize());
}

void ParticleContact::resolveVelocity(){
    if(_particles[1] != nullptr){
        Vector3D vrel = *_particles[0]->getInitialVelocity() - *_particles[1]->getInitialVelocity();
        float k = ((_restitution + 1)*(vrel.scalarProduct(_normal)))/(_particles[0]->getInverseMass()+ _particles[1]->getInverseMass());
        Vector3D *newVelocity1 = _particles[0]->getInitialVelocity();
        *newVelocity1 = *newVelocity1 - _normal * (k*_particles[0]->getInverseMass());
        Vector3D *newVelocity2 = _particles[1]->getInitialVelocity();
        *newVelocity2 = *newVelocity2 - _normal * (k*_particles[1]->getInverseMass());
        return;
    }
    Vector3D vrel = *_particles[0]->getInitialVelocity();
    float k = ((_restitution + 1)*(vrel.scalarProduct(_normal)))/(_particles[0]->getInverseMass());
    Vector3D *newVelocity1 = _particles[0]->getInitialVelocity();
    *newVelocity1 = *newVelocity1 - _normal * (k*_particles[0]->getInverseMass());

}

void ParticleContact::resolveInterpenetration(){
    if(_particles[1] == nullptr){
        Vector3D *newPosition = _particles[0]->getPosition();
        *newPosition = _normal * _penetration + *newPosition;
        return;
    }
    float mass1 = 1/_particles[0]->getInverseMass();
    float mass2 = 1/_particles[1]->getInverseMass();
    Vector3D *newPosition1 = _particles[0]->getPosition();
    *newPosition1 = _normal * (mass2/(mass1+mass2) * _penetration) + *newPosition1;

    Vector3D *newPosition2 = _particles[1]->getPosition();
    *newPosition2 = _normal * (-mass1/(mass1+mass2) * _penetration) + *newPosition2;
}

void ParticleContact::resolve(){
    this->resolveInterpenetration();
    this->resolveVelocity();
}
