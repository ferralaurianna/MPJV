#include "quaternion.h"

Quaternion::Quaternion()
{
    _values[0] = 0;
    _values[1] = 0;
    _values[2] = 0;
    _values[3] = 0;
}

Quaternion::Quaternion(float w, float i, float j, float k)
{
    _values[0] = w;
    _values[1] = i;
    _values[2] = j;
    _values[3] = k;
}
