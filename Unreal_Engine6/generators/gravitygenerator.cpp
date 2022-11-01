#include "gravitygenerator.h"

GravityGenerator::GravityGenerator()
{

}

void GravityGenerator::updateForce(Particles *particle, float duration)
{
    particle->addForces((*gravity_)/(particle->getInverseMass()));
}

GravityGenerator::~GravityGenerator()
{
    delete gravity_;
}
