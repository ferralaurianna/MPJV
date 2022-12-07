#ifndef COLLISIONREGISTRERYRIGIDODY_H
#define COLLISIONREGISTRERYRIGIDODY_H

#include <vector>
#include "collisiondata.h"

class collisionRegistreryRigidody
{

public:
    collisionRegistreryRigidody();
    ~collisionRegistreryRigidody();

    void add(Collisiondata collision);

    void remove(int id1, int id2);

    void removeAll(int idSujet);

    void clear();

    void handleCollisions(float duration);

private:
    std::vector<Collisiondata> register_;
};

#endif // COLLISIONREGISTRERYRIGIDODY_H
