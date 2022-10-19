#ifndef GRAVITYGENERATOR_H
#define GRAVITYGENERATOR_H

#include "geneinterface.h"

class GravityGenerator : public GeneInterface
{
public:
    GravityGenerator();
    ~GravityGenerator();

    void updateForce (Particles *particle , float duration);

private:
    Vector3D* gravity_ = new Vector3D(0,-9.81,0);
};

#endif // GRAVITYGENERATOR_H
