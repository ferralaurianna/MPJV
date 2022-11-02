#ifndef SPRINGFLOTABILITY_H
#define SPRINGFLOTABILITY_H

#include "geneinterface.h"

class SpringFlotability : public GeneInterface
{
public:
    SpringFlotability(Vector3D translation, float k, float l0);
    ~SpringFlotability();

     void updateForce(Particles *particle , float duration);

private:
    Vector3D translation_;
    float k_ = 1;
    float l0_ = 1;
};

#endif // SPRINGFLOTABILITY_H
