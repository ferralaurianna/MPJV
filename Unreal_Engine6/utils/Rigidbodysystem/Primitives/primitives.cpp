#include "primitives.h"

Primitives::Primitives()
{

}
Primitives & Primitives::operator= (const Primitives &prim) {
    if (this == &prim) return *this;
    this->type = prim.type;
    return *this;
}
