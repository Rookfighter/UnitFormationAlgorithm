#ifndef SRC_UFA_COLLISION_CIRCLE_HPP_
#define SRC_UFA_COLLISION_CIRCLE_HPP_

#include "ufa/collision/Vec2f.hpp"

namespace collision
{

    class Circle
    {
    private:
        Vec2f mid_;
        float radius_;
    public:
        Circle(const Vec2f &p_mid, const float p_radius);
        ~Circle();

        const Vec2f& getMid() const;
        float getRadius() const;
    };

}

#endif
