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

    //Quaternion multiplication
    Quaternion operator*(const Quaternion& other);
    void operator*=(const Quaternion& other);

    // Normalize a quaternion.
    void Normalized();

    // Rotate a quaternion by a Vector.
    void RotateByVector(const Vector3D& vect);

    // Apply the quaternion update by the angular velcity.
    void UpdateByAngularVelocity(const Vector3D& vect, float duration);
};

#endif // QUATERNION_H
