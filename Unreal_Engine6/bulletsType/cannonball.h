#ifndef CANNONBALL_H
#define CANNONBALL_H
#include "utils\ParticlesSystem\particles.h"

class Cannonball : public Particles
{
public:
    Cannonball(float posX=0,float posY=0,float posZ=0,float angle_=45);
    void CheckCollision() override;
private:
    float angle_;
};

#endif // CANNONBALL_H
