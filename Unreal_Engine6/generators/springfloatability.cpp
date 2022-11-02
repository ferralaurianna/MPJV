#include "springflotability.h"

SpringFlotability::SpringFlotability(Vector3D translation, float k, float l0)
{
    translation_ = translation + Vector3D(0,0.0001,0);
    k_ = k;
    l0_ = l0;
}

SpringFlotability::~SpringFlotability()
{
}

void SpringFlotability::updateForce(Particles *particle , float duration)
{
    float l = translation_.norm();
    Vector3D force = translation_.normalize()*((l-l0_)*k_);
    particle->addForces(force);
}
