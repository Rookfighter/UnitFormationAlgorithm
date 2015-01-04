#include <cmath>
#include <cassert>
#include <cfloat>
#include <array>
#include "collision/CollisionDetector.hpp"

namespace collision
{

    CollisionDetector::CollisionDetector()
    {
    }

    CollisionDetector::~CollisionDetector()
    {
    }

    Collision CollisionDetector::check(const CollisionObject &p_objectA, const CollisionObject &p_objectB)
    {
        return check(p_objectA.getCirlce(), p_objectB.getCirlce());
    }

    Collision CollisionDetector::check(const Circle &p_circleA,
            const Circle &p_circleB)
    {
        Collision result;
        // check if circles collide
        result.collide = circlesCollide(p_circleA, p_circleB);
        if(result.collide)
            result.minTranslationVector = getCircleTranslationVector(p_circleA,
                    p_circleB);

        return result;
    }

    bool CollisionDetector::circlesCollide(const Circle &p_circleA,
            const Circle &p_circleB)
    {
        float radiusSum = p_circleA.getRadius() + p_circleB.getRadius();
        return (p_circleA.getMid() - p_circleB.getMid()).lengthSQ()
                <= radiusSum * radiusSum;
    }

    Vec2f CollisionDetector::getCircleTranslationVector(const Circle &p_circleA,
            const Circle &p_circleB)
    {
        Vec2f minTranslationVector;

        // axis are the standard axis of coordinate system
        std::array<Vec2f, 2> axis;
        axis[0].set(0, 1);
        axis[1].set(1, 0);

        float minIntervalDistance = FLT_MAX;
        Vec2f minIntervalAxis;

        for(unsigned int i = 0; i < axis.size(); ++i) {
            Interval intervalA = getProjectionIntervalCircle(axis[i],
                    p_circleA);
            Interval intervalB = getProjectionIntervalCircle(axis[i],
                    p_circleB);
            float intervalDistance = fabs(
                    getIntervalDistance(intervalA, intervalB));
            if(intervalDistance < minIntervalDistance) {
                minIntervalDistance = intervalDistance;
                minIntervalAxis = axis[i];
            }
        }

        // calc vector from B to A, so the direction we want to translate A
        Vec2f midDistance = p_circleA.getMid() - p_circleB.getMid();
        // project vector on axis with smallest interval distance
        // if translationAxis points in opposite direction than vector then
        // result is negative
        if(midDistance * minIntervalAxis < 0)
            minIntervalAxis.invert();

        minTranslationVector = minIntervalAxis * minIntervalDistance;
        return minTranslationVector;
    }

    Collision CollisionDetector::check(const CollisionObject &p_object, const CollisionTile &p_tile)
    {
        Rectangle rect = p_tile.getRect();
        Circle circle = p_object.getCirlce();
        Collision result = check(circle, rect);

        if(result.collide && p_tile.isFineGrained()) {
            std::vector<Rectangle> fineGrainedRects;
            p_tile.getFineGrainedRects(fineGrainedRects);
            result = check(circle, fineGrainedRects);
        }

        return result;
    }

    Collision CollisionDetector::check(const Circle &p_circle,
            const std::vector<Rectangle> &p_rects)
    {
        Collision result;
        result.collide = false;
        float translationDistanceSQ = FLT_MAX;

        for(unsigned int i = 0; p_rects.size(); ++i) {
            Collision collision = check(p_circle, p_rects[i]);
            if(collision.collide
                    && collision.minTranslationVector.lengthSQ()
                            < translationDistanceSQ) {
                result.collide = true;
                result.minTranslationVector = collision.minTranslationVector;
            }
        }

        return result;
    }

    Collision CollisionDetector::check(const Circle &p_circle,
            const Rectangle &p_rect)
    {
        Collision result;
        result.collide = true;

        std::array<Vec2f, 3> axis;
        axis[0].set(1, 0);
        axis[1].set(0, 1);
        axis[2] = getAxisToClosestCorner(p_circle.getMid(), p_rect);
        float minTranslationDistanceSQ = FLT_MAX;

        for(unsigned int i = 0; i < axis.size(); ++i) {
            Collision currentCollision = getCollisionOf(axis[i], p_circle,
                    p_rect);

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
        Vec2f closestCorner = p_rect.getCorners()[0];
        float distanceSQ = (p_circleMid - closestCorner).lengthSQ();

        for(unsigned int i = 1; i < p_rect.getCorners().size(); ++i) {
            float distanceSQTmp =
                    (p_circleMid - p_rect.getCorners()[i]).lengthSQ();
            if(distanceSQTmp < distanceSQ) {
                closestCorner = p_rect.getCorners()[i];
                distanceSQ = distanceSQTmp;
            }
        }

        Vec2f diffVec = (p_circleMid - closestCorner);
        diffVec.normalize();
        return diffVec;
    }

    Collision CollisionDetector::getCollisionOf(const Vec2f &p_axis,
            const Circle &p_circle, const Rectangle &p_rect)
    {
        Collision result;
        result.collide = true;
        Interval circleInterval = getProjectionIntervalCircle(p_axis, p_circle);
        Interval rectInterval = getProjectionIntervalRect(p_axis, p_rect);

        float intervalDistance = getIntervalDistance(circleInterval,
                rectInterval);
        if(intervalDistance > 0) {
            result.collide = false;
        } else {
            intervalDistance = fabs(intervalDistance);
            Vec2f translationAxis = p_axis;

            // vector from rect center to circle mid which is direction in wich we
            // want to translate circle
            Vec2f diff = p_circle.getMid() - p_rect.getCenter();
            // project vector on translationAxis
            // if translationAxis points in opposite direction
            // the result is negative
            if(diff * translationAxis < 0)
                translationAxis.invert();
            result.minTranslationVector = intervalDistance * translationAxis;
        }

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

        for(unsigned int i = 1; i < p_rect.getCorners().size(); ++i) {
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

    float CollisionDetector::getIntervalDistance(const Interval& p_intervalA,
            const Interval& p_intervalB)
    {
        if(p_intervalA.min < p_intervalB.min)
            return p_intervalB.min - p_intervalA.max;
        else
            return p_intervalA.min - p_intervalB.max;
    }
}
