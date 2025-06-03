#include "LinearSystem.hpp"

LinearSystem::LinearSystem(const Matrix& matA, const Vector& vecB)
    : A(matA), b(vecB), mSize(matA.rows()) {}

LinearSystem::~LinearSystem() {}

Vector LinearSystem::Solve() {
    // Gaussian elimination with partial pivoting
    Matrix aug(mSize, mSize + 1);
    
    for (int i = 1; i <= mSize; ++i) {
        for (int j = 1; j <= mSize; ++j)
            aug(i, j) = A(i, j);
        aug(i, mSize + 1) = b(i);
    }

    for (int k = 1; k <= mSize; ++k) {
        // Pivoting
        int maxRow = k;
        for (int i = k + 1; i <= mSize; ++i)
            if (abs(aug(i, k)) > abs(aug(maxRow, k)))
                maxRow = i;

        for (int j = 1; j <= mSize + 1; ++j)
            swap(aug(k, j), aug(maxRow, j));

        // Eliminate
        for (int i = k + 1; i <= mSize; ++i) {
            double factor = aug(i, k) / aug(k, k);
            for (int j = k; j <= mSize + 1; ++j)
                aug(i, j) -= factor * aug(k, j);
        }
    }

    // Back substitution
    Vector x(mSize);
    for (int i = mSize; i >= 1; --i) {
        double sum = aug(i, mSize + 1);
        for (int j = i + 1; j <= mSize; ++j)
            sum -= aug(i, j) * x(j);
        x(i) = sum / aug(i, i);
    }

    return x;
}