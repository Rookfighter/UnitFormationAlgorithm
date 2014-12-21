#include "Circle.hpp"

namespace collision
{

    Circle::Circle(const Vec2f& p_mid, const float p_radius)
    : mid_(p_mid), radius_(p_radius)
    {
    }

    Circle::~Circle()
    {
    }

    const Vec2f& Circle::getMid() const
    {
        return mid_;
    }

    float Circle::getRadius() const
    {
        return radius_;
    }

}
