#include <cmath>
#include <cassert>
#include <cfloat>
#include "ufa/collision/CollisionDetector.hpp"

namespace collision
{

    CollisionDetector::CollisionDetector()
    {
    }

    CollisionDetector::~CollisionDetector()
    {
    }

    Collision CollisionDetector::check(CollisionObject *a, CollisionObject *b,
            const float p_deltaSec)
    {
        Collision result;

        Vec2f axis = b->getPosition() - a->getPosition();
        axis.normalize();
        Interval intervalA = getProjectionIntervalCircle(axis, a->getPosition(),
                a->getRadius());
        Interval intervalB = getProjectionIntervalCircle(axis, b->getPosition(),
                b->getRadius());
        result.collide = calcIntervalDistance(intervalA, intervalB) <= 0;

        float velProjection = axis * a->getVelocity();

        if(velProjection < 0)
            intervalA.min += velProjection;
        else
            intervalA.max += velProjection;

        float intervalDistance = calcIntervalDistance(intervalA, intervalB);
        result.willCollide = intervalDistance <= 0;

        Vec2f midDistance = b->getPosition() - a->getPosition();
        if(midDistance * axis < 0)
            axis.invert();

        result.minTranslationVector = axis * intervalDistance;

        return result;
    }

    bool CollisionDetector::checkCircleCircle(const Vec2f &p_midA,
            const float p_radiusA, const Vec2f &p_midB, const float p_radiusB)
    {
        return (p_midA - p_midB).lengthSQ()
                <= (p_radiusA + p_radiusB) * (p_radiusA + p_radiusB);
    }

    Collision CollisionDetector::check(CollisionObject *a, CollisionTile *b,
            const float p_deltaSec)
    {
    }

    CollisionDetector::Interval CollisionDetector::getProjectionIntervalRect(
            const Vec2f& p_axis, const std::vector<Vec2f> &p_rectCorners)
    {
        assert(p_rectCorners.size() > 0);

        float scalarProduct = p_rectCorners[0] * p_axis;
        Interval result;
        result.min = scalarProduct;
        result.max = scalarProduct;

        for(unsigned int i = 0; i < p_rectCorners.size(); ++i) {
            scalarProduct = p_rectCorners[i] * p_axis;
            if(scalarProduct < result.min)
                result.min = scalarProduct;
            else if(scalarProduct > result.max)
                result.max = scalarProduct;
        }

        return result;
    }

    CollisionDetector::Interval CollisionDetector::getProjectionIntervalCircle(
            const Vec2f& p_axis, const Vec2f& p_mid, const float p_radius)
    {
        float scalarProduct = p_axis * p_mid;
        Interval result;
        result.min = scalarProduct - p_radius;
        result.max = scalarProduct + p_radius;
        return result;
    }

    float CollisionDetector::calcIntervalDistance(const Interval& p_intervalA,
            const Interval& p_intervalB)
    {
        if(p_intervalA.min < p_intervalB.min)
            return p_intervalB.min - p_intervalA.max;
        else
            return p_intervalA.min - p_intervalB.max;
    }

}
