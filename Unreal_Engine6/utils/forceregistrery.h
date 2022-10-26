#ifndef FORCEREGISTRERY_H
#define FORCEREGISTRERY_H

#include "generators/geneinterface.h"
#include "utils/particles.h"
#include <vector>

class ForceRegistrery
{


public:
    ForceRegistrery();
    ~ForceRegistrery();

    void add(ParticleContact* contact);
    void clear();

    void updateContact();

private:
    vector<ParticleContact> register_;
};

#endif // FORCEREGISTRERY_H
