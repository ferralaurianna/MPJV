#ifndef FORCEGENERATOR_H
#define FORCEGENERATOR_H

#include "utils/Rigidbodysystem/rigidbody.h"
#include "utils/Vector3D.h"

class ForceGenerator
{
public:
    ForceGenerator();
    virtual void updateForce (Rigidbody * rigidbody, float duration) = 0;
    virtual ~ForceGenerator() = 0;
};

#endif // FORCEGENERATOR_H
