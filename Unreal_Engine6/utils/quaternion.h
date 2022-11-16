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

    // Getter
    float  getW() const { return _values[0];}
    float getI() const { return _values[1];}
    float getJ() const { return _values[2];}
    float getK() const { return _values[3];}
};

#endif // QUATERNION_H
