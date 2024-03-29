#ifndef PARTICLECONTACT_H
#define PARTICLECONTACT_H

#include "particles.h"
#include "utils\Vector3D.h"

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
    void resolveInterpenetration();

public:
    ParticleContact(){};

    ParticleContact(Particles *p1, Vector3D normal, float restitution, float penetration);

    ParticleContact(Particles *p1, Particles *p2, float restitution);

    ~ParticleContact() {};

    //Methodes

    void resolve();

    float calculateSeparationVelocity();

};

#endif // PARTICLECONTACT_H
