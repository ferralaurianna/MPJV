#include "cannonball.h"

// Override of the Particle constructor with the cannonball's physical features
Cannonball::Cannonball(float posX,float posY,float posZ,float angle)
{
    position_=new Vector3D(posX,posY,posZ);

    inverseMass_=1/1000;
    angle_=angle;
    float velocity = 5000;
    velocity_=new Vector3D(velocity*qCos(qDegreesToRadians(angle_)),velocity*qSin(qDegreesToRadians(angle_)),0);

    damping_ = 0.5;
    *gravity = Vector3D(0,-20000,0);
    type_=CANNONBALL;

    radius_=0.5;
}
