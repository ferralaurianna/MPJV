#include "forceregistrery.h"

ForceRegistrery::ForceRegistrery()
{

}

void ForceRegistrery::add(Particles* particle, GeneInterface* fg)
{
    register_.push_back({particle,fg});
}

void ForceRegistrery::clear()
{
    register_.clear();
}

void ForceRegistrery::updateForces(float duration)
{
    for(Registration i: register_)
    {
        i.forceGen->updateForce(i.particle,duration);
    }
}
