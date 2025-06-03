#include "Vector.hpp"
#include "Matrix.hpp"
#include "LinearSystem.hpp"
#include "PosSymLinSystem.hpp"

int main() {
    // Test for LinearSystem
    Matrix A(3, 3);
    A(1, 1) = 2; A(1, 2) = -1; A(1, 3) = 0;
    A(2, 1) = -1; A(2, 2) = 2; A(2, 3) = -1;
    A(3, 1) = 0; A(3, 2) = -1; A(3, 3) = 2;

    Vector b(3);
    b(1) = 1;
    b(2) = 0;
    b(3) = 1;

    LinearSystem system(A, b);
    Vector x = system.Solve();

    cout << "Solution using Gaussian Elimination:" << endl;
    x.Print();

    // Test for PosSymLinSystem
    if (A.isSymmetric()) {
        PosSymLinSystem symSystem(A, b);
        Vector x2 = symSystem.Solve();
        cout << "Solution using Conjugate Gradient:" << endl;
        x2.Print();
    } else {
        cout << "Matrix is not symmetric." << endl;
    }

    return 0;
}