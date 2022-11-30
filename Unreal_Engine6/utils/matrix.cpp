#include "matrix.h"
using namespace std;

// Constructors
Matrix::Matrix(){
    _matrix = nullptr;
    _size = 0;
}

Matrix::Matrix(long int size){
    _matrix = new float[size*size]();
    _size = size;
}

Matrix::Matrix(long int size, float *tab){
    _matrix = new float[size*size];
    memcpy(_matrix, tab, size*size*sizeof(float));
    _size = size;    
}

Matrix::Matrix(const Matrix &other){
    if(other._matrix == nullptr){
        _matrix = nullptr;
        _size = 0;
        return;
    }
    _matrix = new float[other._size*other._size];
    memcpy(_matrix,other._matrix,other._size*other._size*sizeof(float));
    _size = other._size;
}

Matrix::Matrix(Matrix && other){
    _matrix = other._matrix;
    _size = other._size;
    other._matrix = nullptr;
}

// Destructor
Matrix::~Matrix(){
    delete [] _matrix;
}

Matrix Matrix::operator=(const Matrix &other){
    if(other._matrix == nullptr){
        _matrix = nullptr;
        _size = 0;
    }
    else
    {
        _matrix = new float[other._size*other._size];
        memcpy(_matrix,other._matrix,other._size*other._size*sizeof(float));
        _size = other._size;
    }

    return *this;
}

Matrix Matrix::operator=(Matrix &&other){
    delete [] _matrix;
    _matrix = other._matrix;
    _size = other._size;
    other._matrix = nullptr;
    return *this;
}

// Operator to get a line of the matrix
float* Matrix::operator[](int i) const{
    if(i > _size-1){
        throw "The index is greater than the number of column.";
    }
    float *tab = new float[_size];
    tab = &_matrix[i*_size];
    return tab;
}

// Operator to get a specific cell of the matrix
float& Matrix::operator()(int i, int j) const{
    if(i > _size-1){
        throw "The index is greater than the number of column.";
    }
    if(j > _size-1){
        throw "The index is greater than the number of line";
    }
    return _matrix[i*_size + j];
}

// Addition operator
Matrix Matrix::operator+(Matrix const& other){
    if(_size != other._size){
        throw "They are not the same size, the addition cannot be done.";
    }
    Matrix result = Matrix(_size);
    for(int i = 0; i < _size*_size;i++){
        result._matrix[i] = _matrix[i] + other._matrix[i];
    }
    return result;
}

// Substraction operator
Matrix Matrix::operator-(Matrix const& other){
    if(_size != other._size){
        throw "They are not the same size, the subtraction cannot be done.";
    }
    Matrix result = Matrix(_size);
    for(int i = 0; i < _size*_size;i++){
        result._matrix[i] = _matrix[i] - other._matrix[i];
    }
    return result;
}

// Unary operator
Matrix Matrix::operator-(){
    Matrix result = Matrix(_size);
    for(int i = 0; i < _size*_size; i++){
        result._matrix[i] = -_matrix[i];
    }
    return result;
}

// Mutliplication between two matrix
Matrix Matrix::operator*(Matrix const& other){
    if(_size != other._size){
        throw "The matrix product cannot be done because the matrix dont have the same size.";
    }
    int sum = 0;
    Matrix result = Matrix(_size);
    for(int i = 0; i < result._size; i++){
        for(int j = 0; j < result._size; j++){
            sum = 0;
            for(int k = 0; k < _size; k++){
                sum += _matrix[i*_size + k]*other._matrix[k*other._size + j];
            }
            result._matrix[i*result._size + j] = sum;
        }
    }
    return result;
}

// Multiplication between a matrix and a scalar
Matrix Matrix::operator*(float scalar){
    Matrix result = Matrix(_size);
    for(int i = 0; i < result._size*result._size; i++){
        result._matrix[i] = _matrix[i] * scalar;
    }
    return result;
}

// Product between a vector and a matrix. If the matrix has not a size 3, it return an error.
Vector3D Matrix::operator*(const Vector3D& vect){
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
    if(_size != 3){
        throw "The matrix has not the right size. It should be a 3-Matrix.";
    }
    for(int j = 0; j < 3; j++){
        x += _matrix[j] * vect.getX();
        y += _matrix[j + _size] * vect.getY();
        z += _matrix[j + 2*_size] * vect.getZ();
    }
    Vector3D result(x,y,z);
    return result;
}

// Division between a matrix and a scalar
Matrix Matrix::operator/(float scalar){
    Matrix result = Matrix(_size);
    for(int i = 0; i < result._size* result._size; i++){
        result._matrix[i] = _matrix[i] / scalar;
    }
    return result;
}

// Get the transposed matrix
Matrix Matrix::Transpose(){
    Matrix result = Matrix(_size);
    for(int i = 0;i<result._size;i++){
        for(int j = 0; j<result._size;j++){
            result._matrix[i*result._size + j] = _matrix[j*_size + i];
        }
    }
    return result;
}

// Calculation of the determinant of a 3x3 matrix
float Matrix::Determinant(){
    float result = 0.f;
    if(_size == 3){
        result += _matrix[0] * (_matrix[4] * _matrix[8] - _matrix[7] * _matrix[5]);
        result -= _matrix[3] * (_matrix[2] * _matrix[8] - _matrix[7] * _matrix[2]);
        result += _matrix[6] * (_matrix[1] * _matrix[5] - _matrix[4] * _matrix[2]);
    }
    return result;
}

Matrix Matrix::Inverse(){
    if(_size == 3){
        float det = this->Determinant();
        if(det == 0){
            Matrix m;
            return m;
        }
        Matrix result(3);
        result._matrix[0] = (_matrix[4] * _matrix[8] - _matrix[5] * _matrix[7]) / det;
        result._matrix[1] = (_matrix[2] * _matrix[7] - _matrix[1] * _matrix[8]) / det;
        result._matrix[2] = (_matrix[1] * _matrix[5] - _matrix[2] * _matrix[4]) / det;
        result._matrix[3] = (_matrix[5] * _matrix[6] - _matrix[3] * _matrix[8]) / det;
        result._matrix[4] = (_matrix[0] * _matrix[8] - _matrix[2] * _matrix[6]) / det;
        result._matrix[5] = (_matrix[2] * _matrix[3] - _matrix[0] * _matrix[5]) / det;
        result._matrix[6] = (_matrix[3] * _matrix[7] - _matrix[4] * _matrix[6]) / det;
        result._matrix[7] = (_matrix[1] * _matrix[6] - _matrix[0] * _matrix[7]) / det;
        result._matrix[8] = (_matrix[0] * _matrix[4] - _matrix[1] * _matrix[3]) / det;
        return result;
    }
    if(_size == 4){
        float mat[9] = {_matrix[0],_matrix[1],_matrix[2],_matrix[4],_matrix[5],_matrix[6],_matrix[8],_matrix[9],_matrix[10]};
        Vector3D v(_matrix[3],_matrix[7],_matrix[11]);

        Matrix m(3,mat);
        Matrix mInverse=m.Inverse();
        Vector3D mIV=mInverse*v*(-1);

        Matrix result(4);
        result._matrix[0] = mInverse(0,0);
        result._matrix[1] = mInverse(0,1);
        result._matrix[2] = mInverse(0,2);
        result._matrix[3] = mIV[0];
        result._matrix[4] = mInverse(1,0);
        result._matrix[5] = mInverse(1,1);
        result._matrix[6] = mInverse(1,2);
        result._matrix[7] = mIV[1];
        result._matrix[8] = mInverse(2,0);
        result._matrix[9] = mInverse(2,1);
        result._matrix[10] = mInverse(2,2);
        result._matrix[11] = mIV[2];
        result._matrix[12] = 0;
        result._matrix[13] = 0;
        result._matrix[14] = 0;
        result._matrix[15] = 1;
        return result;
    }
    else{
        Matrix result;
        return result;
    }
}

Matrix Matrix::To4()
{
    if(_size==3)
    {
        float mat[16] = {_matrix[0],_matrix[1],_matrix[2],0,_matrix[3],_matrix[4],_matrix[5],0,_matrix[6],_matrix[7],_matrix[8,0,0,0,0,1]};
        Matrix m(4,mat);
        return m;
    }
    else{return *this;}
}

Matrix Matrix::To3()
{
    if(_size==4)
    {
        float mat[9] = {_matrix[0],_matrix[1],_matrix[2],_matrix[4],_matrix[5],_matrix[6],_matrix[8],_matrix[9],_matrix[10]};
        Matrix m(3,mat);
        return m;
    }
    else{return *this;}
}

void Matrix::SetOrientation(const Quaternion& q){
    if(_size != 3){
        return;
    }
    float w = q.getW();
    float x = q.getI();
    float y = q.getJ();
    float z = q.getK();
    _matrix[0] = 1 - (2*y*y + 2*z*z);
    _matrix[1] = 2*x*y + 2*z*w;
    _matrix[2] = 2*x*z - 2*y*w;
    _matrix[3] = 2*x*y - 2*z*w;
    _matrix[4] = 1 - (2*x*x + 2*x*w);
    _matrix[5] = 2*y*z + 2*x*w;
    _matrix[6] = 2*x*z + 2*y*w;
    _matrix[7] = 2*y*z - 2*x*w;
    _matrix[8] = 1 - (2*x*x + 2*y*y);
}

void Matrix::SetOrientationAndPosition(const Quaternion& q, const Vector3D& vect){
    if(_size != 4){
        return;
    }
    float w = q.getW();
    float x = q.getI();
    float y = q.getJ();
    float z = q.getK();
    _matrix[0] = 1 - (2*y*y + 2*z*z);
    _matrix[1] = 2*x*y + 2*z*w;
    _matrix[2] = 2*x*z - 2*y*w;
    _matrix[4] = 2*x*y - 2*z*w;
    _matrix[5] = 1 - (2*x*x + 2*x*w);
    _matrix[6] = 2*y*z + 2*x*w;
    _matrix[8] = 2*x*z + 2*y*w;
    _matrix[9] = 2*y*z - 2*x*w;
    _matrix[10] = 1 - (2*x*x + 2*y*y);

    _matrix[3] = vect.getX();
    _matrix[6] = vect.getY();
    _matrix[9] = vect.getZ();
}

Vector3D Matrix::TransformPosition(const Vector3D& vector){
    if(_size != 4){
        Vector3D result;
        return result;
    }
    float xRes;
    float yRes;
    float zRes;
    float x = vector.getX();
    float y = vector.getY();
    float z = vector.getZ();
    xRes = _matrix[0] * x + _matrix[1]*y + _matrix[2]*z + _matrix[3];
    yRes = _matrix[4] * x + _matrix[5]*y + _matrix[6]*z + _matrix[7];
    zRes = _matrix[8] * x + _matrix[9]*y + _matrix[10]*z + _matrix[11];
    Vector3D result(xRes, yRes, zRes);
    return result;
}

Vector3D Matrix::TransformDirection(const Vector3D& vector){
    if(_size != 4){
        Vector3D result;
        return result;
    }
    float xRes;
    float yRes;
    float zRes;
    float x = vector.getX();
    float y = vector.getY();
    float z = vector.getZ();
    xRes = _matrix[0] * x + _matrix[1]*y + _matrix[2]*z;
    yRes = _matrix[4] * x + _matrix[5]*y + _matrix[6]*z;
    zRes = _matrix[8] * x + _matrix[9]*y + _matrix[10]*z;
    Vector3D result(xRes, yRes, zRes);
    return result;
}

