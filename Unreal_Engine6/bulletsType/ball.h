#ifndef BALL_H
#define BALL_H
#include "utils\particles.h"

class Ball: public Particles
{
public:
    Ball(float posX=0,float posY=0,float posZ=0,float angle_=45);
};

#endif // BALL_H
