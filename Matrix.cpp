#include "Matrix.hpp"
#include <cmath>

Matrix::Matrix(int numRows, int numCols) {
    assert(numRows > 0 && numCols > 0);
    mNumRows = numRows;
    mNumCols = numCols;

    mData = new double*[mNumRows];
    for (int i = 0; i < mNumRows; ++i) {
        mData[i] = new double[mNumCols];
        for (int j = 0; j < mNumCols; ++j)
            mData[i][j] = 0.0;
    }
}

Matrix::Matrix(const Matrix& other) {
    mNumRows = other.mNumRows;
    mNumCols = other.mNumCols;
    mData = new double*[mNumRows];
    for (int i = 0; i < mNumRows; ++i) {
        mData[i] = new double[mNumCols];
        for (int j = 0; j < mNumCols; ++j)
            mData[i][j] = other.mData[i][j];
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < mNumRows; ++i)
        delete[] mData[i];
    delete[] mData;
}

int Matrix::GetNumRows() const {
    return mNumRows;
}

int Matrix::GetNumCols() const {
    return mNumCols;
}

double& Matrix::operator()(int i, int j) {
    assert(i >= 1 && i <= mNumRows);
    assert(j >= 1 && j <= mNumCols);
    return mData[i - 1][j - 1];
}

double Matrix::operator()(int i, int j) const {
    assert(i >= 1 && i <= mNumRows);
    assert(j >= 1 && j <= mNumCols);
    return mData[i - 1][j - 1];
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) return *this;

    if (mNumRows != other.mNumRows || mNumCols != other.mNumCols) {
        for (int i = 0; i < mNumRows; ++i)
            delete[] mData[i];
        delete[] mData;

        mNumRows = other.mNumRows;
        mNumCols = other.mNumCols;
        mData = new double*[mNumRows];
        for (int i = 0; i < mNumRows; ++i)
            mData[i] = new double[mNumCols];
    }

    for (int i = 0; i < mNumRows; ++i)
        for (int j = 0; j < mNumCols; ++j)
            mData[i][j] = other.mData[i][j];

    return *this;
}

Matrix Matrix::operator+(const Matrix& other) const {
    assert(mNumRows == other.mNumRows && mNumCols == other.mNumCols);
    Matrix result(mNumRows, mNumCols);
    for (int i = 0; i < mNumRows; ++i)
        for (int j = 0; j < mNumCols; ++j)
            result.mData[i][j] = mData[i][j] + other.mData[i][j];
    return result;
}

Matrix Matrix::operator-(const Matrix& other) const {
    assert(mNumRows == other.mNumRows && mNumCols == other.mNumCols);
    Matrix result(mNumRows, mNumCols);
    for (int i = 0; i < mNumRows; ++i)
        for (int j = 0; j < mNumCols; ++j)
            result.mData[i][j] = mData[i][j] - other.mData[i][j];
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    assert(mNumCols == other.mNumRows);
    Matrix result(mNumRows, other.mNumCols);
    for (int i = 0; i < mNumRows; ++i)
        for (int j = 0; j < other.mNumCols; ++j)
            for (int k = 0; k < mNumCols; ++k)
                result.mData[i][j] += mData[i][k] * other.mData[k][j];
    return result;
}

Matrix Matrix::operator*(double scalar) const {
    Matrix result(mNumRows, mNumCols);
    for (int i = 0; i < mNumRows; ++i)
        for (int j = 0; j < mNumCols; ++j)
            result.mData[i][j] = mData[i][j] * scalar;
    return result;
}

Vector Matrix::operator*(const Vector& vec) const {
    assert(mNumCols == vec.GetSize());
    Vector result(mNumRows);
    for (int i = 0; i < mNumRows; ++i) {
        double sum = 0.0;
        for (int j = 0; j < mNumCols; ++j)
            sum += mData[i][j] * vec(j + 1);
        result(i + 1) = sum;
    }
    return result;
}

bool Matrix::isSymmetric() const {
    if (mNumRows != mNumCols) return false;
    for (int i = 0; i < mNumRows; ++i)
        for (int j = 0; j < mNumCols; ++j)
            if (mData[i][j] != mData[j][i]) return false;
    return true;
}

void Matrix::Print() const {
    for (int i = 0; i < mNumRows; ++i) {
        for (int j = 0; j < mNumCols; ++j)
            cout << mData[i][j] << " ";
        cout << endl;
    }
}

// Dummy implementations for Determinant, Inverse, PseudoInverse
double Matrix::Determinant() const {
    assert(mNumRows == mNumCols);
    // Not implemented
    return 0.0;
}

Matrix Matrix::Inverse() const {
    assert(mNumRows == mNumCols);
    // Not implemented
    return Matrix(mNumRows, mNumCols);
}

Matrix Matrix::PseudoInverse() const {
    // Not implemented
    return Matrix(mNumCols, mNumRows);
}
