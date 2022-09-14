#include "Vector3D.h"
#include <math.h>

//Constructor
Vector3D::Vector3D(){
    _x = 0;
    _y = 0;
    _z = 0;
}

Vector3D::Vector3D(float x, float y, float z){
    _x = x;
    _y = y;
    _z = z;
}

Vector3D::Vector3D(const Vector3D &other){
    _x = other._x;
    _y = other._y;
    _z = other._z;
}

Vector3D::Vector3D(Vector3D && other){
    _x = other._x;
    _y = other._y;
    _z = other._z;
}

float Vector3D::operator[](int i) const{
    switch (i)
    {
    case 0:
        return _x;
        break;
    case 1:
        return _y;
        break;
    case 2:
        return _z;
        break;
    default:
        throw "Bad index.";
        break;
    }
}

Vector3D Vector3D::operator+(Vector3D const& other){
    Vector3D result = Vector3D();
    result._x = _x + other._x;
    result._y = _y + other._y;
    result._z = _z + other._z;
    return result;
}

Vector3D Vector3D::operator-(){
    Vector3D result = Vector3D();
    result._x = -_x;
    result._y = -_y;
    result._z = -_z;
    return result;
}

Vector3D Vector3D::operator-(Vector3D const& other){
    Vector3D result = Vector3D();
    result._x = _x - other._x;
    result._y = _y - other._y;
    result._z = _z - other._z;
    return result;
}

Vector3D Vector3D::operator^(Vector3D const& other){
    Vector3D result = Vector3D();
    result._x = _y * other._z - _z * other._y;
    result._y = _z * other._x - _x * other._z;
    result._z = _x * other._y - _y * other._x;
    return result;
}

Vector3D Vector3D::operator*(Vector3D const& other){
    Vector3D result = Vector3D();
    result._x = _x * other._x;
    result._y = _y * other._y;
    result._z = _z * other._z;
    return result;
}

Vector3D Vector3D::operator*(Matrix const& other){
    Vector3D result = Vector3D();
    if(other.getSize() != 3){
        throw "The matrix has not the right size. It should be a 3-Matrix.";
    }
    for(int j = 0; j < 3; j++){
        result._x = result._x + other(0, j) * _x;
         result._y = result._y + other(1, j) * _y;
         result._z = result._z + other(2, j) * _z;
    }
    return result;
}


Vector3D Vector3D::operator*(float scalar){
    Vector3D result = Vector3D();
    result._x = _x * scalar;
    result._y = _y * scalar;
    result._z = _z * scalar;
    return result;
}

Vector3D Vector3D::operator/(float scalar){
    Vector3D result = Vector3D();
    result._x = _x / scalar;
    result._y = _y / scalar;
    result._z = _z / scalar;
    return result;
}

float Vector3D::norm() const {
    float result = _x *_x + _y * _y + _z * _z;
    return sqrt(result);
}

float Vector3D::squareNorm() const {
    return _x *_x + _y * _y + _z * _z;
}

Vector3D Vector3D::normalize() const {
    float norm = this->norm();
    Vector3D result;
    result._x = _x / norm;
    result._y = _y / norm;
    result._z = _z / norm;
    return result;
}

float Vector3D::scalarProduct(Vector3D const& other) const{
    return _x * other._x + _y * other._y + _z * other._z;
}
