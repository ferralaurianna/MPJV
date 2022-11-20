#ifndef INPUTFORCEGENERATOR_H
#define INPUTFORCEGENERATOR_H

#include "forcegenerator.h"

class InputForceGenerator : public ForceGenerator
{
public:
    InputForceGenerator(Vector3D direction = Vector3D(0.f,9.8f,0.f));

    void updateForce(Rigidbody* rigidbody,  float duration);

private:

    Vector3D direction_ = Vector3D(0.f,0.f,0.f);
};

#endif // INPUTFORCEGENERATOR_H
