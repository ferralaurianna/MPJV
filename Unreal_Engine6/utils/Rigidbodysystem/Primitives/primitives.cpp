#include "primitives.h"

Primitives::Primitives()
{

}

Primitives::Primitives(const Primitives& other)
{
    localPosition_ = other.localPosition_;
    type = other.type;
    radiusOroffset_ = other.radiusOroffset_;
    normalOrhalfsize = other.normalOrhalfsize;
}
Primitives & Primitives::operator= (const Primitives &prim) {
    if (this == &prim) return *this;
    this->type = prim.type;
    return *this;
}
