#ifndef GENEINTERFACE_H
#define GENEINTERFACE_H

#include "utils/particles.h"
#include "utils/Vector3D.h"


class GeneInterface
{
public:
    virtual void updateForce (Particles *particle , float duration) = 0;
    virtual ~GeneInterface();
};

#endif // GENEINTERFACE_H
