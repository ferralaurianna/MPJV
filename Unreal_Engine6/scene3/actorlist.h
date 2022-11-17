#ifndef ACTORLIST_H
#define ACTORLIST_H

#include "utils/Rigidbodysystem/actors.h"
#include "utils/Rigidbodysystem/physicsystem.h"
#include <vector>

class ActorList
{
public:
    ActorList();

    void addActor(Actors actor);

    void removeActor(int id);

    void removeGravity(int id);

    void addGravity(int id);

    void addLink(int id, int idOther);

    void removeLink(int id, int idOther);

    void addCable(int id, int idOther);

    void removeCable(int id, int idOther);

    Actors* getActor(int id);



private:
    std::vector<Actors> list;

    PhysicSystem physic;


};

#endif // ACTORLIST_H
