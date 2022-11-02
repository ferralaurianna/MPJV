#include "collisionregistrery.h"

CollisionRegistrery::CollisionRegistrery()
{

}

void CollisionRegistrery::add(ParticleContact contact)
{
    register_.push_back(contact);
}

void CollisionRegistrery::clear()
{
//    for(Registration i: register_)
//    {
//        if(i.forceGen!=nullptr)
//        {
//            delete i.forceGen;
//        }
//    }
    register_.clear();
}

void CollisionRegistrery::handleCollision()
{
    for(ParticleContact i: register_)
    {
        i.resolve();
    }
}

CollisionRegistrery::~CollisionRegistrery()
{
    clear();
}
