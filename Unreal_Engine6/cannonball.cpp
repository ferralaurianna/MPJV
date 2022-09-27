#include "cannonball.h"

Cannonball::Cannonball(float posX,float posY,float posZ,float angle)
{
    position_=new Vector3D(posX,posY,posZ);

    inverseMass_=1/1000;
    angle_=angle;
    float velocity = 500;
    velocity_=new Vector3D(velocity*qCos(qDegreesToRadians(angle_)),velocity*qSin(qDegreesToRadians(angle_)),0);

    damping_ = 0.5;
    *gravity = Vector3D(0,-400.0,0);
    type_=CANNONBALL;

    radius_=0.5;
}
