#ifndef COLLISION_COLLISION_DETECTOR_HPP
#define COLLISION_COLLISION_DETECTOR_HPP

#include "collision/CollisionObject.hpp"
#include "collision/CollisionTile.hpp"

namespace collision
{
    struct Collision {
        bool collide;
        Vec2f minTranslationVector;
    };

    class CollisionDetector
    {
    private:
        CollisionDetector();
        ~CollisionDetector();

        struct Interval {
            float min;
            float max;
        };

        static bool circlesCollide(const Circle &p_circleA, const Circle &p_circleB);
        static Vec2f getCircleTranslationVector(const Circle &p_circleA, const Circle &p_circleB);

        static Vec2f getAxisToClosestCorner(const Vec2f &p_circleMid, const Rectangle &p_rect);
        static Collision getCollisionOf(const Vec2f &p_axis, const Circle &p_circle, const Rectangle &p_rect);

        static Interval getProjectionIntervalRect(const Vec2f &p_axis, const Rectangle &p_rect);
        static Interval getProjectionIntervalCircle(const Vec2f &p_axis, const Circle &p_circle);
        static float getIntervalDistance(const Interval &p_intervalA, const Interval &p_intervalB);
    public:
        static Collision check(const CollisionObject &p_objectA, const CollisionObject &p_objectB);
        static Collision check(const CollisionObject &p_object, const CollisionTile &p_tile);

        static Collision check(const Circle &p_circleA, const Circle &p_circleB);
        static Collision check(const Circle &p_circle, const std::vector<Rectangle> &p_rects);
        static Collision check(const Circle &p_circle, const Rectangle &p_rect);

    };
}

#endif
