#ifndef CANNONBALL_H
#define CANNONBALL_H
#include "utils\particles.h"

class Cannonball : public Particles
{
public:
    Cannonball(float posX=0,float posY=0,float posZ=0,float angle_=45);
};

#endif // CANNONBALL_H
