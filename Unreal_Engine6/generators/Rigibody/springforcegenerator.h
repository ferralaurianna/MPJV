#ifndef SPRINGFORCEGENERATOR_H
#define SPRINGFORCEGENERATOR_H

#include "forcegenerator.h"

class SpringForceGenerator : public ForceGenerator
{   
private:
    Vector3D  bodyAnchor_;
    Rigidbody * otherRigidbody_;
    Vector3D  otherBodyAnchor_;

    float k_;
    float restLenght_;

public:
    //Ne pas appeler avec des arguments par défaut
    SpringForceGenerator(Vector3D bodyAnchor= Vector3D(0.f,0.f,0.f),
                         Rigidbody* otherRigidbody= new Rigidbody(),
                         Vector3D otherBodyAnchor= Vector3D(2.f,2.f,2.f),
                         float k=5, float restLenght=2);
    ~SpringForceGenerator();
     void updateForce(Rigidbody* rigidbody,float duration);
};

#endif // SPRINGFORCEGENERATOR_H
