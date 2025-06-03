#include "Vector.hpp"
#include <iostream>

using namespace std;

Vector::Vector(int size) : mSize(size), mData(size, 0.0) {}

Vector::Vector(const Vector& other) : mSize(other.mSize), mData(other.mData) {}

Vector::~Vector() {}

int Vector::GetSize() const {
    return mSize;
}


double& Vector::operator[](int index) {
    if (index < 0 || index >= mSize)
        cout << "Index out of bounds (0-based)\n";
    return mData[index];
}

double Vector::operator[](int index) const {
    if (index < 0 || index >= mSize)
        cout << "Index out of bounds (0-based)\n";
    return mData[index];
}

double& Vector::operator()(int index) {
    if (index < 1 || index > mSize)
        cout << "Index out of bounds (1-based)\n";
    return mData[index - 1];
}

double Vector::operator()(int index) const {
    if (index < 1 || index > mSize)
        cout << "Index out of bounds (1-based)\n";
    return mData[index - 1];
}

Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        mSize = other.mSize;
        mData = other.mData;
    }
    return *this;
}

Vector Vector::operator+(const Vector& other) const {
    Vector result(mSize);
    for (int i = 0; i < mSize; ++i)
        result.mData[i] = mData[i] + other.mData[i];
    return result;
}

Vector Vector::operator-(const Vector& other) const {
    Vector result(mSize);
    for (int i = 0; i < mSize; ++i)
        result.mData[i] = mData[i] - other.mData[i];
    return result;
}

Vector Vector::operator*(double scalar) const {
    Vector result(mSize);
    for (int i = 0; i < mSize; ++i)
        result.mData[i] = mData[i] * scalar;
    return result;
}

double Vector::dot(const Vector& other) const {
    double result = 0.0;
    for (int i = 0; i < mSize; ++i)
        result += mData[i] * other.mData[i];
    return result;
}

void Vector::print() const {
    for (int i = 0; i < mSize; ++i)
        cout << mData[i] << endl;
}