#include "inputforcegenerator.h"

InputForceGenerator::InputForceGenerator(Vector3D direction)
{
    direction_ = direction;
}

void InputForceGenerator::updateForce(Rigidbody* rigidbody,  float duration)
{
    rigidbody->addForces(direction_);
}
