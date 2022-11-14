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

Quaternion::Quaternion(float values[4])
{
    _values[0] = values[0];
    _values[1] = values[1];
    _values[2] = values[2];
    _values[3] = values[3];
}

Quaternion Quaternion::operator*(const Quaternion& other)
{
    Quaternion result;
    result._values[0] = _values[0]*other._values[0] - _values[1]*other._values[1] - _values[2]*other._values[2] - _values[3]*other._values[3];
    result._values[0] = _values[0]*other._values[1] + _values[1]*other._values[0] + _values[2]*other._values[3] - _values[3]*other._values[2];
    result._values[0] = _values[0]*other._values[2] + _values[2]*other._values[0] + _values[3]*other._values[1] - _values[1]*other._values[3];
    result._values[0] = _values[0]*other._values[3] + _values[3]*other._values[0] + _values[1]*other._values[2] - _values[2]*other._values[1];
    return result;
}
