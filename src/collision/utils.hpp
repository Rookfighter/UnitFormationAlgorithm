#ifndef COLLISION_UTILS_HPP
#define COLLISION_UTILS_HPP

#include <cmath>

namespace collision
{
    inline bool sameFloat(const float a, const float b, const float eps)
    {
        return fabs(a - b) < eps;
    }
}

#endif
