#ifndef LASER_H
#define LASER_H
#include "utils\particles.h"

class Laser : public Particles
{
public:
    Laser(float posX=0,float posY=0,float posZ=0,float angle_=45);

    void display() override;
    void CheckCollision() override;
private:
    float angle_;
};

#endif // LASER_H
