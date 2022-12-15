#ifndef PHYSICSYSTEM_H
#define PHYSICSYSTEM_H

#include <QObject>
#include "utils/Rigidbodysystem/collisionregistreryrigidody.h"
#include "utils/Rigidbodysystem/forceregistreryrigidbody.h"
#include "utils/Rigidbodysystem/narrowphasedetector.h"
#include "utils/octree.h"

class PhysicSystem
{

public:
    PhysicSystem();

    void addSimpleForce(Rigidbody* rb, int id, int idForce, Vector3D bodyAnchor=Vector3D(0,0,0));

    void addForcesBetween(int id, int idOther, int idForce,
                          Rigidbody* rb,Vector3D bodyAnchor= Vector3D(0.f,0.f,0.f),
                          Rigidbody* otherRigidbody= new Rigidbody(), Vector3D otherBodyAnchor= Vector3D(0.f,0.f,0.f),
                          float k=5, float restLenght=2);

    void removeForce(int id, int idOther);

    void UpdateForces(float duration);

    bool handleCollisions(float duration);

    void removeForces(int id);

    void addMoved(int id){movedThisframe_.push_back(id);};

    void addToCollision(Actors* actor);

    void removeCollisions(int id);

    void CalculateCollision();

private:
    ForceRegistreryRigidbody forces_;

    std::vector<int> movedThisframe_;

    std::vector<std::tuple<Actors*, Actors*>> possibleCollisions_;

    collisionRegistreryRigidody collisions_;

    NarrowPhaseDetector narrowPhase = NarrowPhaseDetector(&collisions_,&possibleCollisions_);

    Octree octree = Octree(-100,-100,-100,100,100,100);

signals:
    void collisionFound();

};

#endif // PHYSICSYSTEM_H
