#include "matrix.h"
using namespace std;

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


Matrix::~Matrix(){
    delete [] _matrix;
}


void Matrix::display(){
    cout << "[";
    for(int i = 0; i<_size; i++){
        cout << "[";
        for(int j = 0; j<_size-1; j++){
            cout << _matrix[i*_size+j] << ", ";
        }
        cout << _matrix[i*_size+_size-1];
        cout << "]";
        if(i != _size-1){
            cout << ", ";
        }
        
    }
    cout << "]"<< endl;
}

Matrix Matrix::operator=(const Matrix &other){
    _size = other._size;
    return *this;
}

Matrix Matrix::operator=(Matrix &&other){
    delete [] _matrix;
    _matrix = other._matrix;
    _size = other._size;
    other._matrix = nullptr;
    return *this;
}

float* Matrix::operator[](int i) const{
    if(i > _size-1){
        throw "The index is greater than the number of column.";
    }
    float *tab = new float[_size];
    tab = &_matrix[i*_size];
    return tab;
}

float& Matrix::operator()(int i, int j) const{
    if(i > _size-1){
        throw "The index is greater than the number of column.";
    }
    if(j > _size-1){
        throw "The index is greater than the number of line";
    }
    return _matrix[i*_size + j];
}

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

Matrix Matrix::operator-(){
    Matrix result = Matrix(_size);
    for(int i = 0; i < _size*_size; i++){
        result._matrix[i] = -_matrix[i];
    }
    return result;
}

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

Matrix Matrix::operator*(float scalar){
    Matrix result = Matrix(_size);
    for(int i = 0; i < result._size; i++){
        result._matrix[i] = _matrix[i] * scalar;
    }
    return result;
}

Matrix Matrix::operator/(float scalar){
    Matrix result = Matrix(_size);
    for(int i = 0; i < result._size; i++){
        result._matrix[i] = _matrix[i] / scalar;
    }
    return result;
}

ostream& operator<<(ostream &os, Matrix const& m){
    os << "[";
    for(int i = 0; i<m._size; i++){
        os << "[";
        for(int j = 0; j<m._size-1; j++){
            os << m._matrix[i*m._size+j] << ", ";
        }
        os << m._matrix[i*m._size+m._size-1];
        os << "]";
        if(i != m._size-1){
            os << ", ";
        }
        
    }
    os << "]";
    return os;
}


Matrix Matrix::transpose(){
    Matrix result = Matrix(_size);
    for(int i = 0;i<result._size;i++){
        for(int j = 0; j<result._size;j++){
            result._matrix[i*result._size + j] = _matrix[j*_size + i];
        }
    }
    return result;
}

Matrix Matrix::orthogonalize(){
    Matrix result = Matrix(_size);
    // TO BE DONE.
    return result;
}
