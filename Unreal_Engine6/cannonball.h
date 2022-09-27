#ifndef CANNONBALL_H
#define CANNONBALL_H
#include "particles.h"

class Cannonball : public Particles
{
public:
    Cannonball(float posX=0,float posY=0,float posZ=0,float radius=1,float inverseMass=1,float velocity=1,float angle_=45);

};

#endif // CANNONBALL_H
