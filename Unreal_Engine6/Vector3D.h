#ifndef VECTOR3D_H
#define VECTOR3D_H

#include "matrix.h"

class Vector3D {
private:
    float _x;
    float _y;
    float _z;
public:
    //Constructor
    Vector3D();
    Vector3D(float x, float y, float z);
    Vector3D(const Vector3D &other);
    Vector3D(Vector3D && other);

    //Setter
    void setX(float x){
        _x = x;
    }
    void setY(float y){
        _y = y;
    }
    void setZ(float z){
        _z = z;
    }

    //Getter
    float getX() const {
        return _x;
    }
    float getY() const {
        return _y;
    }
    float getZ() const {
        return _z;
    }

    //Operation
    float operator[](int i) const;
    Vector3D operator+(Vector3D const& other);
    Vector3D operator-(Vector3D const& other);
    Vector3D operator-();
    Vector3D operator^(Vector3D const& other);
    Vector3D operator*(Vector3D const& other);
    Vector3D operator*(float scalar);
    Vector3D operator*(Matrix const& matrix);
    Vector3D operator/(float scalar);
    Vector3D operator=(const Vector3D & other);

    //Method
    float norm() const;
    float squareNorm() const;
    Vector3D normalize() const;
    float scalarProduct(Vector3D const& other) const;
};


// Projection de u sur v.
#endif //VECTOR3D_H
