#include "ball.h"

Ball::Ball(float posX,float posY,float posZ,float angle)
{
    position_=new Vector3D(posX,posY,posZ);

    inverseMass_=1/1000;
    angle_=angle;
    float velocity = 500;
    velocity_=new Vector3D(velocity*qCos(qDegreesToRadians(angle_)),velocity*qSin(qDegreesToRadians(angle_)),0);

    damping_ = 0.9;
    *gravity = Vector3D(0,-400.0,0);
    type_ = BALL;

    radius_=0.5;
}