#include "cannonball.h"

// Override of the Particle constructor with the cannonball's physical features
Cannonball::Cannonball(float posX,float posY,float posZ,float angle)
{
    position_=new Vector3D(posX,posY,posZ);

    inverseMass_=1;
    float velocity = 2500;
    velocity_=new Vector3D(velocity*qCos(qDegreesToRadians(angle)),velocity*qSin(qDegreesToRadians(angle)),0);
    angle_ = angle;

    damping_ = 0.5;
    *accumForce_ = Vector3D(0,-15000,0);

    radius_=0.5;
}

void Cannonball::CheckCollision()
{
    if(position_->getY()<0)
    {
        clearAccum();
        hasReachedGround=true;
        velocity_->setX(0);velocity_->setY(0);velocity_->setZ(0);
        position_->setY(0);
    }
}
