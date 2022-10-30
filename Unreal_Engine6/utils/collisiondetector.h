#ifndef COLLISIONDETECTOR_H
#define COLLISIONDETECTOR_H


#include "utils/collisionregistrery.h"
class CollisionDetector
{
public:
    CollisionDetector(CollisionRegistrery* registery);

    void detectCollision(Particles* part, vector<float[8]> walls);

private:
    CollisionRegistrery* registery_;
};

#endif // COLLISIONDETECTOR_H
