#ifndef FORCEREGISTRERY_H
#define FORCEREGISTRERY_H

#include "generators/geneinterface.h"
#include "utils/particles.h"
#include <vector>

class ForceRegistrery
{

    struct Registration
    {
        Particles * particle;
        GeneInterface *forceGen;
    };

public:
    ForceRegistrery();

    void add(Particles* particle, GeneInterface* fg);
    void clear();

    void updateForces(float duration);

private:
    vector<Registration> register_;
};

#endif // FORCEREGISTRERY_H
