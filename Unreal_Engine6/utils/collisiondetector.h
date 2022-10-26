#ifndef COLLISIONDETECTOR_H
#define COLLISIONDETECTOR_H


#include "utils/collisionregistrery.h"
class CollisionDetector
{
public:
    CollisionDetector();

    void detectCollision(Particles* part, vector<float[8]> walls, CollisionRegistrery* registery);
};

#endif // COLLISIONDETECTOR_H
