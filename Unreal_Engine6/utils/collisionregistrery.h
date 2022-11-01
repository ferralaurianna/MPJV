#ifndef COLLISIONREGISTRERY_H
#define COLLISIONREGISTRERY_H


#include "utils/particlecontact.h"
class CollisionRegistrery
{
public:
    CollisionRegistrery();
    ~CollisionRegistrery();

    void add(ParticleContact contact);
    int size(){return register_.size();};
    void clear();

    void handleCollision();

private:
    vector<ParticleContact> register_;
};

#endif // COLLISIONREGISTRERY_H
