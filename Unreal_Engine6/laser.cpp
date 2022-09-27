#include "laser.h"

Laser::Laser(float posX,float posY,float posZ,float radius,float inverseMass,float velocity,float angle)
{
    position_=new Vector3D(posX,posY,posZ);

    radius_=radius;
    inverseMass_=inverseMass;
    angle_=angle;
    velocity_=new Vector3D(velocity*qCos(qDegreesToRadians(angle_)),velocity*qSin(qDegreesToRadians(angle_)),0);

    damping_ = 1;
    *gravity = Vector3D();
    type_=LASER;
}
