#ifndef PARTICLECONTACT_H
#define PARTICLECONTACT_H

#include "particles.h"
#include "Vector3D.h"

class ParticleContact
{
private:
    // Attributes

    Particles* _particles[2];

    float _restitution;

    float _penetration;

    Vector3D _normal;

    //Impulsion
    void resolveVelocity();

    //Interpenetration
    void resolveInterpenetration(){
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

public:
    ParticleContact();

    ParticleContact(Particles *p1, Vector3D normal, float restitution);

    ParticleContact(Particles *p1, Particles *p2, float restitution);

    //Methodes

    void resolve(float duration);

    float calculateSeparationVelocity();



};

#endif // PARTICLECONTACT_H
