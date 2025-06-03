#include "PosSymLinSystem.hpp"

PosSymLinSystem::PosSymLinSystem(const Matrix& matA, const Vector& vecB)
    : LinearSystem(matA, vecB) {}

Vector PosSymLinSystem::Solve() {
    // Conjugate Gradient Method
    Vector x(mSize); // Initial guess = 0
    Vector r = b - (A * x);
    Vector p = r;
    double rs_old = r.dot(r);

    for (int i = 0; i < mSize; ++i) {
        Vector Ap = A * p;
        double alpha = rs_old / p.dot(Ap);
        x = x + p * alpha;
        r = r - Ap * alpha;
        double rs_new = r.dot(r);
        if (rs_new < 1e-10) break;
        p = r + p * (rs_new / rs_old);
        rs_old = rs_new;
    }

    return x;
}