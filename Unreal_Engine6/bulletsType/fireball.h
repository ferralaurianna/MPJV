#ifndef FIREBALL_H
#define FIREBALL_H
#include "utils\ParticlesSystem\particles.h"

class FireBall : public Particles
{
public:
    FireBall(float posX=0,float posY=0,float posZ=0,float angle_=45);

    void display() override;
    void CheckCollision() override;
private:
    float angle_;
};

#endif // FIREBALL_H
