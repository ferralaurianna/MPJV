#ifndef ACTORLIST_H
#define ACTORLIST_H

#include "utils/Rigidbodysystem/actors.h"
#include "utils/Rigidbodysystem/physicsystem.h"
#include <vector>

class ActorList
{
public:
    ActorList();

    void setPhysic(PhysicSystem* physic){physic_=physic;};

    void addActor(Actors actor);

    void removeActor(int id);

    void removeGravity(int id);

    void addGravity(int id);

    void addLink(int id, int idOther,Vector3D bodyAnchor = Vector3D(0,0,0), Vector3D otherBodyAnchor = Vector3D(0,0,0));

    void removeLink(int id, int idOther);

    void addCable(int id, int idOther,Vector3D bodyAnchor = Vector3D(0,0,0), Vector3D otherBodyAnchor = Vector3D(0,0,0));

    void removeCable(int id, int idOther);

    Actors* getActor(int id);

    void clearForces();

    void integrateAll(float duration);



private:
    std::vector<Actors> list;

    PhysicSystem* physic_;


};

#endif // ACTORLIST_H
