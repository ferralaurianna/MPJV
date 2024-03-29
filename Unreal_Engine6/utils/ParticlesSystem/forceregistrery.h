#ifndef FORCEREGISTRERY_H
#define FORCEREGISTRERY_H

#include "generators/geneinterface.h"
#include "utils/ParticlesSystem/particles.h"
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
    ~ForceRegistrery();

    void add(Particles* particle, GeneInterface* fg);
    void clear();

    void updateForces(float duration);

private:
    std::vector<Registration> register_;
};

#endif // FORCEREGISTRERY_H
