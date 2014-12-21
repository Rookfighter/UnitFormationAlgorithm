#ifndef COLLISION_RECTANGLE_HPP
#define COLLISION_RECTANGLE_HPP

#include <vector>
#include "collision/Vec2f.hpp"

namespace collision
{

    class Rectangle
    {
    private:
        Vec2f center_;
        Vec2f size_;
        std::vector<Vec2f> corners_;
    public:
        Rectangle(const Vec2f &p_center, const Vec2f &p_size);
        ~Rectangle();

        const Vec2f& getCenter() const;
        Vec2f getTopLeft() const;
        const Vec2f& getSize() const;
        const std::vector<Vec2f>& getCorners() const;
    };

}

#endif
