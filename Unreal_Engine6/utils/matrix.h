#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <cstring>
#include <math.h>
#include "quaternion.h"

using namespace std;

class Matrix{

private:
    float *_matrix;
    long int _size;

public:
    //Constructor
    Matrix();
    Matrix(long int size);
    Matrix(long int size, float *tab);
    Matrix(const Matrix &other);
    Matrix(Matrix && other);
    ~Matrix();

    //Getter
    long int getSize() const {
        return _size;
    }

    //Operation
    Matrix operator=(const Matrix & other);
    Matrix operator=(Matrix &&other);
    float* operator[](int i) const;
    float& operator()(int i, int j) const;
    Matrix operator+(Matrix const& other);
    Matrix operator-(Matrix const& other);
    Matrix operator-();
    Matrix operator*(Matrix const& other);
    Vector3D operator*(Vector3D const& vect);
    Matrix operator*(float scalar);
    Matrix operator/(float scalar);

    //Method
    Matrix Transpose();
    float Determinant();
    Matrix Inverse();
    void SetOrientation(const Quaternion& q);
    void SetOrientationAndPosition(const Quaternion& q, const Vector3D& p);

};


#endif /* MATRIX_H */
