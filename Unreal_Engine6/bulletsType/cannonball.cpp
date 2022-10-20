#include "cannonball.h"

// Override of the Particle constructor with the cannonball's physical features
Cannonball::Cannonball(float posX,float posY,float posZ,float angle)
{
    position_=new Vector3D(posX,posY,posZ);

    inverseMass_=1/1000;
    float velocity = 2500;
    velocity_=new Vector3D(velocity*qCos(qDegreesToRadians(angle)),velocity*qSin(qDegreesToRadians(angle)),0);
    angle_ = angle;

    damping_ = 0.5;
    *accumForce_ = Vector3D(0,-15000,0);

    radius_=0.5;
}
