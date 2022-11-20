#ifndef PHYSICSYSTEM_H
#define PHYSICSYSTEM_H

#include "utils/Rigidbodysystem/forceregistreryrigidbody.h"

class PhysicSystem
{
public:
    PhysicSystem();

    void addSimpleForce(Rigidbody* rb,int id, int idOther, int idForce, Vector3D bodyAnchor=Vector3D(0,0,0));

    void addForcesBetween(int id, int idOther, int idForce,
                          Rigidbody* rb,Vector3D bodyAnchor= Vector3D(0.f,0.f,0.f),
                          Rigidbody* otherRigidbody= new Rigidbody(), Vector3D otherBodyAnchor= Vector3D(0.f,0.f,0.f),
                          float k=5, float restLenght=2);

    void removeForce(int id, int idOther);

    void UpdateForces(float duration);

    void removeForces(int id);

private:
    ForceRegistreryRigidbody forces_;
};

#endif // PHYSICSYSTEM_H
