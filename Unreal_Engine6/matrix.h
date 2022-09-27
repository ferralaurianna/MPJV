#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <cstring>
#include <math.h>

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
    Matrix operator*(float scalar);
    Matrix operator/(float scalar);
    friend ostream& operator<<(ostream &os, const Matrix & m);

    //Method
    Matrix transpose();
    float determinant();
    //Static method
    static Matrix identity(long int n){
        Matrix result = Matrix(n);
        for(int  i = 0; i < n; i++){
            result[i][i] = 1;
        }
        return result;
    }
    static Matrix rotation(long int n, float angle, long int axis = -1){
        Matrix result = Matrix(n);
        if(n == 2){
            result._matrix[0] = cos(angle);
            result._matrix[1] = -sin(angle);
            result._matrix[2] = sin(angle);
            result._matrix[3] = cos(angle);
        } else if(n == 3) {
            switch (axis)
            {
            case 0: // axis x
                result._matrix[0] = 1;
                result._matrix[1] = 0;
                result._matrix[2] = 0;
                result._matrix[3] = 0;
                result._matrix[4] = cos(angle);
                result._matrix[5] = -sin(angle);
                result._matrix[6] = 0;
                result._matrix[7] = sin(angle);
                result._matrix[8] = cos(angle);
                break;

            case 1: // axis y
                result._matrix[0] = cos(angle);
                result._matrix[1] = 0;
                result._matrix[2] = sin(angle);
                result._matrix[3] = 0;
                result._matrix[4] = 1;
                result._matrix[5] = 0;
                result._matrix[6] = -sin(angle);
                result._matrix[7] = 0;
                result._matrix[8] = cos(angle);
                break;

            case 2: // axis z
                result._matrix[0] = cos(angle);
                result._matrix[1] = -sin(angle);
                result._matrix[2] = 0;
                result._matrix[3] = sin(angle);
                result._matrix[4] = cos(angle);
                result._matrix[5] = 0;
                result._matrix[6] = 0;
                result._matrix[7] = 0;
                result._matrix[8] = 1;
                break;
            default:
                break;
            }
        }
    }

};


#endif /* MATRIX_H */
