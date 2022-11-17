#include "gravityforcegenerator.h"

GravityForceGenerator::GravityForceGenerator(Vector3D* gravity)
{
    gravity_ = gravity;
}

void GravityForceGenerator::updateForce(Rigidbody *rigidbody, float duration)
{
    rigidbody->addForces((*gravity_)/(rigidbody->getInverseMass()));
}

GravityForceGenerator::~GravityForceGenerator()
{
    delete gravity_;
}
