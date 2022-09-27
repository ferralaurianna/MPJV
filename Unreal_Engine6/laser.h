#ifndef LASER_H
#define LASER_H
#include "particles.h"

class Laser : public Particles
{
public:
    Laser(float posX=0,float posY=0,float posZ=0,float radius=1,float inverseMass=1,float velocity=1,float angle_=45);


};

#endif // LASER_H
