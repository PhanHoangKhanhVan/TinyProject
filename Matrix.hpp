#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include "Vector.hpp"

using namespace std;

class Matrix {
private:
    int mNumRows;
    int mNumCols;
    double** mData;

public:
    Matrix(int numRows, int numCols);
    Matrix(const Matrix& other);
    ~Matrix();

    int GetNumRows() const;
    int GetNumCols() const;

    double& operator()(int i, int j);
    double operator()(int i, int j) const;

    Matrix& operator=(const Matrix& other);
    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    Matrix operator*(double scalar) const;
    Vector operator*(const Vector& vec) const;

    double Determinant() const;
    Matrix Inverse() const;
    Matrix PseudoInverse() const;

    bool isSymmetric() const;
    void Print() const;
};

#endif