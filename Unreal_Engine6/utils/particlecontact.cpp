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
