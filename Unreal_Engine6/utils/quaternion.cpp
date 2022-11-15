#include "quaternion.h"
#include <math.h>

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
    result._values[1] = _values[0]*other._values[1] + _values[1]*other._values[0] + _values[2]*other._values[3] - _values[3]*other._values[2];
    result._values[2] = _values[0]*other._values[2] + _values[2]*other._values[0] + _values[3]*other._values[1] - _values[1]*other._values[3];
    result._values[3] = _values[0]*other._values[3] + _values[3]*other._values[0] + _values[1]*other._values[2] - _values[2]*other._values[1];
    return result;
}

void Quaternion::operator*=(const Quaternion& other){
    Quaternion q = *this;
    _values[0] = q._values[0]*other._values[0] - q._values[1]*other._values[1] - q._values[2]*other._values[2] - q._values[3]*other._values[3];
    _values[1] = q._values[0]*other._values[1] + q._values[1]*other._values[0] + q._values[2]*other._values[3] - q._values[3]*other._values[2];
    _values[2] = q._values[0]*other._values[2] + q._values[2]*other._values[0] + q._values[3]*other._values[1] - q._values[1]*other._values[3];
    _values[3] = q._values[0]*other._values[3] + q._values[3]*other._values[0] + q._values[1]*other._values[2] - q._values[2]*other._values[1];
}

void Quaternion::Normalized()
{
    float magnitude = std::sqrt(_values[0]*_values[0] + _values[1]*_values[1] + _values[2]*_values[2] + _values[3]*_values[3]);
    if (magnitude == 0){
        return;
    }
    _values[0] /= magnitude;
    _values[1] /= magnitude;
    _values[2] /= magnitude;
    _values[3] /= magnitude;
}

void Quaternion::RotateByVector(const Vector3D &vect)
{
    Quaternion q(0, vect.getX(), vect.getY(), vect.getZ());
    (*this) *= q;
}


void Quaternion::UpdateByAngularVelocity(const Vector3D& vect, float duration)
{
    Quaternion q(0, vect.getX() * duration, vect.getY() * duration, vect.getZ() * duration);
    q *= *this;
    _values[0] += q._values[0] * (0.5);
    _values[1] += q._values[1] * (0.5);
    _values[2] += q._values[2] * (0.5);
    _values[3] += q._values[3] * (0.5);
}
