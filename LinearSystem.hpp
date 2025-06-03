#ifndef LINEARSYSTEM_HPP
#define LINEARSYSTEM_HPP

#include "Matrix.hpp"
#include "Vector.hpp"
#include <vector>

using namespace std;

class LinearSystem {
protected:
    int mSize;
    Matrix A;
    Vector b;

public:
    LinearSystem(const Matrix& matA, const Vector& vecB);
    virtual ~LinearSystem();

    virtual Vector Solve(); // Gaussian elimination
};

#endif