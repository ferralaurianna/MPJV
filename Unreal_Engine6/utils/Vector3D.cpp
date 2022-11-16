#include "Vector3D.h"
#include <math.h>

//Constructor by default, all the values are set to 0.
Vector3D::Vector3D(){
    _x = 0;
    _y = 0;
    _z = 0;
}

//Constructor using the 3 default value given by the user.
Vector3D::Vector3D(float x, float y, float z){
    _x = x;
    _y = y;
    _z = z;
}

//Constructors using other Vectors.
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

/*
    An operation that give a coordinate depending of an integer.
    0 => x
    1 => y
    2 => z
    Any other integer return an error.
*/
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

// Addition operator.
Vector3D Vector3D::operator+(Vector3D const& other){
    Vector3D result = Vector3D();
    result._x = _x + other._x;
    result._y = _y + other._y;
    result._z = _z + other._z;
    return result;
}

// Unary operator. Give the oposite of the vector.
Vector3D Vector3D::operator-(){
    Vector3D result = Vector3D();
    result._x = -_x;
    result._y = -_y;
    result._z = -_z;
    return result;
}

// Substraction operator.
Vector3D Vector3D::operator-(Vector3D const& other){
    Vector3D result = Vector3D();
    result._x = _x - other._x;
    result._y = _y - other._y;
    result._z = _z - other._z;
    return result;
}

// Vector product.
Vector3D Vector3D::operator^(Vector3D const& other){
    Vector3D result = Vector3D();
    result._x = _y * other._z - _z * other._y;
    result._y = _z * other._x - _x * other._z;
    result._z = _x * other._y - _y * other._x;
    return result;
}

// Product per component.
Vector3D Vector3D::operator*(Vector3D const& other){
    Vector3D result = Vector3D();
    result._x = _x * other._x;
    result._y = _y * other._y;
    result._z = _z * other._z;
    return result;
}

// Product between a vector and a scalar.
Vector3D Vector3D::operator*(float scalar){
    Vector3D result = Vector3D();
    result._x = _x * scalar;
    result._y = _y * scalar;
    result._z = _z * scalar;
    return result;
}

// Division between a vector and a scalar.
Vector3D Vector3D::operator/(float scalar){
    Vector3D result = Vector3D();
    result._x = _x / scalar;
    result._y = _y / scalar;
    result._z = _z / scalar;
    return result;
}

// Assignment operator
Vector3D Vector3D::operator=(const Vector3D &other){
    _x = other._x;
    _y = other._y;
    _z = other._z;
    return *this;
}

// Equality operator
bool Vector3D::operator==(const Vector3D &other){
    return (abs(_x - other._x) < 0.01) && (abs(_y - other._y) < 0.01) && (abs(_z - other._z) < 0.01);
}

// Calculation of the norm.
float Vector3D::norm() const {
    float result = _x *_x + _y * _y + _z * _z;
    return sqrt(result);
}

// Calculation of the square norm.
float Vector3D::squareNorm() const {
    return _x *_x + _y * _y + _z * _z;
}

// Normalize a vector.
Vector3D Vector3D::normalize() const {
    float norm = this->norm();
    Vector3D result;
    result._x = _x / norm;
    result._y = _y / norm;
    result._z = _z / norm;
    return result;
}

// Scalar product between two vectors.
float Vector3D::scalarProduct(Vector3D const& other) const{
    return _x * other._x + _y * other._y + _z * other._z;
}
