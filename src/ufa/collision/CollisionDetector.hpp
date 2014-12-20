#ifndef COLLISION_COLLISION_DETECTOR_HPP
#define COLLISION_COLLISION_DETECTOR_HPP

#include "ufa/collision/CollisionObject.hpp"
#include "ufa/collision/CollisionTile.hpp"

namespace collision
{
    class CollisionDetector
    {
    private:
        CollisionDetector();
        ~CollisionDetector();

    public:
        static bool check(CollisionObject *a, CollisionObject *b);
        static bool check(CollisionObject *a, CollisionTile *b);

        static bool checkCircleCircle(const Vec2f &p_circleMidA,
                const float p_radiusA, const Vec2f &p_circleMidB,
                const float p_radiusB);
        static bool checkCircleRect(const Vec2f& p_circleMid,
                const float p_radius, const Vec2f& p_rectTopLeft,
                const Vec2f& p_rectSize);

        static bool isInRect(const Vec2f& p_position,
                const Vec2f& p_rectTopLeft, const Vec2f& p_rectSize);
        static bool circleIntesectsRect(const Vec2f& p_circleMid,
                const float p_radius, const Vec2f& p_rectTopLeft,
                const Vec2f& p_rectSize);

        static bool intersectTop(const Vec2f& p_circleMid, const float p_radius,
                const Vec2f& p_rectTopLeft, const Vec2f& p_rectSize);
        static bool intersectBot(const Vec2f& p_circleMid, const float p_radius,
                const Vec2f& p_rectTopLeft, const Vec2f& p_rectSize);
        static bool intersectLeft(const Vec2f& p_circleMid,
                const float p_radius, const Vec2f& p_rectTopLeft,
                const Vec2f& p_rectSize);
        static bool intersectRight(const Vec2f& p_circleMid,
                const float p_radius, const Vec2f& p_rectTopLeft,
                const Vec2f& p_rectSize);
    };

}

#endif
