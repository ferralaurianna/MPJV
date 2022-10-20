#ifndef SPRINGTWOPARTICLE_H
#define SPRINGTWOPARTICLE_H

#include "geneinterface.h"

class SpringTwoParticle : public GeneInterface
{
public:
    SpringTwoParticle(Particles* otherPart, float k, float l0);
    ~SpringTwoParticle();

     void updateForce(Particles *particle , float duration);

private:
    Particles* _otherPart;
    float k_ = 1;
    float l0_ = 1;
};

#endif // SPRINGTWOPARTICLE_H
