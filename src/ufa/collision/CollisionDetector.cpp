#include <cmath>
#include <cassert>
#include <cfloat>
#include <array>
#include "ufa/collision/CollisionDetector.hpp"

namespace collision
{

    CollisionDetector::CollisionDetector()
    {
    }

    CollisionDetector::~CollisionDetector()
    {
    }

    Collision CollisionDetector::check(CollisionObject *a, CollisionObject *b)
    {
        Collision result;
        Circle circleA = a->getCirlce();
        Circle circleB = b->getCirlce();

        result.collide = checkCircleCircle(circleA, circleB);
        if(!result.collide)
            return result;

        std::array<Vec2f, 2> axis;
        axis[0].set(0,1);
        axis[1].set(1,0);
        float minIntervalDistance = FLT_MAX;
        Vec2f minIntervalAxis;

        for(unsigned int i = 0; i < axis.size(); ++i) {
            Interval intervalA = getProjectionIntervalCircle(axis[i], circleA);
            Interval intervalB = getProjectionIntervalCircle(axis[i], circleB);
            float intervalDistance = fabs(calcIntervalDistance(intervalA, intervalB));
            if(intervalDistance < minIntervalDistance) {
                minIntervalDistance = intervalDistance;
                minIntervalAxis = axis[i];
            }
        }

        Vec2f midDistance = b->getPosition() - a->getPosition();
        if(midDistance * minIntervalAxis < 0)
            minIntervalAxis.invert();

        result.minTranslationVector = minIntervalAxis * minIntervalDistance;

        return result;
    }

    bool CollisionDetector::checkCircleCircle(const Circle &p_circleA, const Circle &p_circleB)
    {
        return (p_circleA.getMid() - p_circleB.getMid()).lengthSQ()
                <= (p_circleA.getRadius() + p_circleB.getRadius()) * (p_circleA.getRadius() + p_circleB.getRadius());
    }

    Collision CollisionDetector::check(CollisionObject *a, CollisionTile *b)
    {
        Collision result;
        result.collide = true;

        Rectangle rect = b->getRect();
        Circle circle = a->getCirlce();
        std::array<Vec2f, 3> axis;
        axis[0].set(1, 0);
        axis[1].set(0, 1);
        axis[2] = getAxisToClosestCorner(circle.getMid(), rect);
        float minTranslationDistanceSQ = FLT_MAX;

        for(unsigned int i = 0; i < axis.size(); ++i) {
            Collision currentCollision = getCollisionOf(axis[i], circle, rect);

            if(!currentCollision.collide) {
                result.collide = false;
                break;
            }

            float distanceSQ = currentCollision.minTranslationVector.lengthSQ();
            if(distanceSQ < minTranslationDistanceSQ) {
                minTranslationDistanceSQ = distanceSQ;
                result.minTranslationVector =
                        currentCollision.minTranslationVector;
            }
        }

        return result;
    }

    Vec2f CollisionDetector::getAxisToClosestCorner(const Vec2f &p_circleMid,
            const Rectangle &p_rect)
    {
        assert(!p_rect.getCorners().empty());
        unsigned int closestCorner = 0;
        float distanceSQ =
                (p_circleMid - p_rect.getCorners()[closestCorner]).lengthSQ();

        for(unsigned int i = 1; i < p_rect.getCorners().size(); ++i) {
            float distanceSQTmp =
                    (p_circleMid - p_rect.getCorners()[i]).lengthSQ();
            if(distanceSQTmp < distanceSQ) {
                closestCorner = i;
                distanceSQ = distanceSQTmp;
            }
        }

        Vec2f diffVec = (p_circleMid - p_rect.getCorners()[closestCorner]);
        return diffVec.perpendicular();
    }

    Collision CollisionDetector::getCollisionOf(const Vec2f &p_axis,
            const Circle &p_circle, const Rectangle &p_rect)
    {
        Collision result;
        result.collide = true;
        Interval circleInterval = getProjectionIntervalCircle(p_axis, p_circle);
        Interval rectInterval = getProjectionIntervalRect(p_axis, p_rect);

        float intervalDistance = calcIntervalDistance(circleInterval,
                rectInterval);
        if(intervalDistance > 0)
            result.collide = false;

        intervalDistance = fabs(intervalDistance);
        Vec2f translationAxis = p_axis;
        Vec2f diff = p_circle.getMid() - p_rect.getCenter();
        if(diff * translationAxis < 0)
            translationAxis.invert();
        result.minTranslationVector = intervalDistance * translationAxis;

        return result;
    }

    CollisionDetector::Interval CollisionDetector::getProjectionIntervalRect(
            const Vec2f& p_axis, const Rectangle &p_rect)
    {
        assert(!p_rect.getCorners().empty());

        float scalarProduct = p_rect.getCorners()[0] * p_axis;
        Interval result;
        result.min = scalarProduct;
        result.max = scalarProduct;

        for(unsigned int i = 0; i < p_rect.getCorners().size(); ++i) {
            scalarProduct = p_rect.getCorners()[i] * p_axis;
            if(scalarProduct < result.min)
                result.min = scalarProduct;
            else if(scalarProduct > result.max)
                result.max = scalarProduct;
        }

        return result;
    }

    CollisionDetector::Interval CollisionDetector::getProjectionIntervalCircle(
            const Vec2f& p_axis, const Circle &p_circle)
    {
        float scalarProduct = p_axis * p_circle.getMid();
        Interval result;
        result.min = scalarProduct - p_circle.getRadius();
        result.max = scalarProduct + p_circle.getRadius();
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
