#ifndef COLLISIONDATA_H
#define COLLISIONDATA_H

#include "utils/Rigidbodysystem/rigidbody.h"
#include "utils/Vector3D.h"
struct Collisiondata{

    int idbody1;
    int idbody2;
    Vector3D position;
    Vector3D normal;
    float penetration;
    Rigidbody* rigidbody1;
    Rigidbody* rigidbody2;
    float restitution;
    float friction;

    Collisiondata(int id1, int id2, Vector3D pos,Vector3D norm, float pen, float resti, float frict, Rigidbody* body1, Rigidbody* body2) :
        idbody1(id1),idbody2(id2),position(pos),normal(norm),penetration(pen),rigidbody1(body1),rigidbody2(body2),restitution(resti),friction(frict){};
};

inline std::ostream& operator << (std::ostream& os, const Collisiondata& data)
{
   return os << "CollisionData { Position: ["
             << data.position.getX() << "," << data.position.getY() << "," << data.position.getZ() << "], "
             << "Normal: [" << data.normal.getX() << "," << data.normal.getY() << "," << data.normal.getZ() << "], "
             << "Penetration: " << data.penetration << ", "
             << "Restitution: " << data.restitution << ", "
             << "Friction: " << data.friction << " }";
}

#endif // COLLISIONDATA_H
