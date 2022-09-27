#include "ball.h"

Ball::Ball(float posX,float posY,float posZ,float radius,float inverseMass,float velocity,float angle)
{
    position_=new Vector3D(posX,posY,posZ);

    radius_=radius;
    inverseMass_=inverseMass;
    angle_=angle;
    velocity_=new Vector3D(velocity*qCos(qDegreesToRadians(angle_)),velocity*qSin(qDegreesToRadians(angle_)),0);

    damping_ = 0.8;
    *gravity = Vector3D(0,-98.0,0);
    type_ = BALL;
}


