#ifndef GRAVITYFORCEGENERATOR_H
#define GRAVITYFORCEGENERATOR_H

#include "forcegenerator.h"

class GravityForceGenerator : public ForceGenerator
{

private:
Vector3D gravity_;

public:
    GravityForceGenerator(Vector3D* gravity= new Vector3D(0.f,9.8f,0.f));
    ~GravityForceGenerator();
    void updateForce(Rigidbody* rigidbody);
};

#endif // GRAVITYFORCEGENERATOR_H
