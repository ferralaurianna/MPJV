#ifndef QUATERNION_H
#define QUATERNION_H

#include "Vector3D.h"

class Quaternion
{
private:
    // w, i, j, k
    float _values[4];
public:
    Quaternion();
    Quaternion(float values[4]);
    Quaternion(float w, float i, float j, float k);

    Quaternion operator*(const Quaternion& other);

    void Normalized();

    void RotateByVector(const Vector3D& vect);
};

#endif // QUATERNION_H
