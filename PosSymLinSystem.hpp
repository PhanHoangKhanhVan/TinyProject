#ifndef POSSYMLINSYSTEM_HPP
#define POSSYMLINSYSTEM_HPP

#include "LinearSystem.hpp"

class PosSymLinSystem : public LinearSystem {
public:
    PosSymLinSystem(const Matrix& matA, const Vector& vecB);
    virtual Vector Solve(); // Override using Conjugate Gradient
};

#endif