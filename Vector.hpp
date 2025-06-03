#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Vector {
private:
    int mSize;
    double* mData;

public:
    Vector(int size);
    Vector(const Vector& other);
    ~Vector();

    int GetSize() const;

    double& operator()(int index);
    double operator()(int index) const;
    Vector& operator=(const Vector& other);
    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;
    double dot(const Vector& other) const;

    void Print() const;
};

#endif
