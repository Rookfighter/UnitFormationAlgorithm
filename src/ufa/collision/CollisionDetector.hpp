#ifndef COLLISION_COLLISION_DETECTOR_HPP
#define COLLISION_COLLISION_DETECTOR_HPP

#include "ufa/collision/CollisionObject.hpp"
#include "ufa/collision/CollisionTile.hpp"

namespace collision
{
    struct Collision {
        bool willCollide;
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

        static bool checkCircleCircle(const Vec2f &p_midA, const float p_radiusA, const Vec2f &p_midB, const float p_radiusB);
        static Interval getProjectionIntervalRect(const Vec2f &p_axis, const std::vector<Vec2f> &p_rectCorners);
        static Interval getProjectionIntervalCircle(const Vec2f &p_axis, const Vec2f &p_mid, const float p_radius);
        static float calcIntervalDistance(const Interval &p_intervalA, const Interval &p_ibtervalB);
    public:
        static Collision check(CollisionObject *a, CollisionObject *b, const float p_deltaSec = 1.0f);
        static Collision check(CollisionObject *a, CollisionTile *b, const float p_deltaSec = 1.0f);


    };

}

#endif
