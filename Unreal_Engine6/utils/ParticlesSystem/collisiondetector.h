#ifndef COLLISIONDETECTOR_H
#define COLLISIONDETECTOR_H


#include "utils/ParticlesSystem/collisionregistrery.h"
#include "utils/polygon.h"
class CollisionDetector
{
public:

    CollisionDetector(CollisionRegistrery* registery, std::vector<std::vector<Polygone>*>* walls);

    void detectCollision(Particles* part);

    void setWalls(std::vector<std::vector<Polygone>*>* walls){walls_=walls;};

private:
    CollisionRegistrery* registery_;

    std::vector<std::vector<Polygone>*>* walls_;

    int rayRectangleIntersect(Vector3D orig, Vector3D dir,Vector3D v0, Vector3D v1, Vector3D v2, Vector3D v3);

    int rayTriangleIntersect(Vector3D orig, Vector3D dir,Vector3D v0, Vector3D v1, Vector3D v2);

    Vector3D P =  Vector3D(0,0,0);
};

#endif // COLLISIONDETECTOR_H
