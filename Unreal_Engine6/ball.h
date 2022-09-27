#ifndef BALL_H
#define BALL_H
#include "particles.h"

class Ball: public Particles
{
public:
    Ball(float posX=0,float posY=0,float posZ=0,float radius=1,float inverseMass=1,float velocity=1,float angle_=45);

};

#endif // BALL_H
