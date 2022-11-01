#ifndef COLLISIONDETECTOR_H
#define COLLISIONDETECTOR_H


#include "utils/collisionregistrery.h"
#include "utils/Polygon.h"
class CollisionDetector
{
public:

    CollisionDetector(CollisionRegistrery* registery, vector<vector<Polygone>*>* walls);

    void detectCollision(Particles* part);

private:
    CollisionRegistrery* registery_;

    vector<vector<Polygone>*>* walls_;

    int rayRectangleIntersect(Vector3D orig, Vector3D dir,Vector3D v0, Vector3D v1, Vector3D v2, Vector3D v3);

    int rayTriangleIntersect(Vector3D orig, Vector3D dir,Vector3D v0, Vector3D v1, Vector3D v2);

    Vector3D P =  Vector3D(0,0,0);
};

#endif // COLLISIONDETECTOR_H
