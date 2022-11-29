#ifndef COLLISIONDATA_H
#define COLLISIONDATA_H

#include "utils/Rigidbodysystem/rigidbody.h"
#include "utils/Vector3D.h"
struct Collisiondata{

    Vector3D position;
    Vector3D normal;
    float penetration;
    Rigidbody* rigidbody1;
    Rigidbody* rigidbody2;
    float restitution;
    float friction;

    Collisiondata(Vector3D pos,Vector3D norm, float pen, float resti, float frict, Rigidbody* body1, Rigidbody* body2) :
        position(pos),normal(norm),penetration(pen),restitution(resti),friction(frict),rigidbody1(body1),rigidbody2(body2){};
};

#endif // COLLISIONDATA_H
