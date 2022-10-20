#include "springtwoparticle.h"

SpringTwoParticle::SpringTwoParticle(Particles* otherPart, float k, float l0)
{
    _otherPart = otherPart;
    k_ = k;
    l0_ = l0;
}

SpringTwoParticle::~SpringTwoParticle()
{
    delete _otherPart;
}

void SpringTwoParticle::updateForce(Particles *particle , float duration)
{
    Vector3D difference= (*(particle->getPosition()) - *(_otherPart->getPosition()));
    Vector3D force = difference.normalize()*((difference.norm()-l0_)*k_);
    particle->addForces(force);
}
