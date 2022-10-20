#ifndef GENEINTERFACE_H
#define GENEINTERFACE_H

#include "utils/particles.h"
#include "utils/Vector3D.h"


class GeneInterface
{
public:
    GeneInterface();
    virtual void updateForce (Particles *particle , float duration) = 0;
    virtual ~GeneInterface() = 0;
};

#endif // GENEINTERFACE_H
