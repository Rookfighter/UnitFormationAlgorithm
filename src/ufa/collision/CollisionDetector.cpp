#include <cmath>
#include "ufa/collision/CollisionDetector.hpp"

namespace collision
{

    CollisionDetector::CollisionDetector()
    {
    }

    CollisionDetector::~CollisionDetector()
    {
    }

    bool CollisionDetector::check(CollisionObject *a, CollisionObject *b)
    {
        return checkCircleCircle(a->getPosition(), a->getRadius(), b->getPosition(), b->getRadius());
    }

    bool CollisionDetector::check(CollisionObject *a, CollisionTile *b)
    {
        if(b->isFineGrained())
            return checkCircleRect(a->getPosition(), a->getRadius(),
                    b->getTopLeft(), b->getTileSize());
        else {
            return false;
        }
    }

    bool CollisionDetector::checkCircleCircle(const Vec2f &p_circleMidA,
            const float p_radiusA, const Vec2f &p_circleMidB,
            const float p_radiusB)
    {
        // circle-circle collision
        return (p_circleMidA - p_circleMidB).lengthSQ()
                <= (p_radiusA + p_radiusB) * (p_radiusA + p_radiusB);
    }

    bool CollisionDetector::checkCircleRect(const Vec2f& p_circleMid,
            const float p_radius, const Vec2f& p_rectTopLeft,
            const Vec2f& p_rectSize)
    {
        bool collided = false;
        // check if mid of circle is in rect
        collided = isInRect(p_circleMid, p_rectTopLeft, p_rectSize);
        if(collided)
            return true;

        // check if distance to sides of rect is shorter than radius
        collided = circleIntesectsRect(p_circleMid, p_radius, p_rectTopLeft,
                p_rectSize);
        if(collided)
            return collided;

        // check if corners are in circle
        Vec2f topRight, botLeft, botRight;

        topRight.set(p_rectTopLeft.x + p_rectSize.x, p_rectTopLeft.y);
        botLeft.set(p_rectTopLeft.x, p_rectTopLeft.y - p_rectSize.y);
        botRight.set(p_rectTopLeft.x + p_rectSize.x,
                p_rectTopLeft.y - p_rectSize.y);
        collided = (p_rectTopLeft - p_circleMid).lengthSQ()
                <= p_radius * p_radius
                || (topRight - p_circleMid).lengthSQ() <= p_radius * p_radius
                || (botLeft - p_circleMid).lengthSQ() <= p_radius * p_radius
                || (botRight - p_circleMid).lengthSQ() <= p_radius * p_radius;

        return collided;
    }

    bool CollisionDetector::isInRect(const Vec2f &p_position,
            const Vec2f &p_rectTopLeft, const Vec2f &p_rectSize)
    {
        return p_position.x <= p_rectTopLeft.x + p_rectSize.x
                && p_position.x >= p_rectTopLeft.x
                && p_position.y <= p_rectTopLeft.y
                && p_position.y >= p_rectTopLeft.y - p_rectSize.y;
    }

    bool CollisionDetector::circleIntesectsRect(const Vec2f &p_circleMid,
            const float p_radius, const Vec2f &p_rectTopLeft,
            const Vec2f &p_rectSize)
    {
        return intersectTop(p_circleMid, p_radius, p_rectTopLeft, p_rectSize)
                || intersectBot(p_circleMid, p_radius, p_rectTopLeft,
                        p_rectSize)
                || intersectLeft(p_circleMid, p_radius, p_rectTopLeft,
                        p_rectSize)
                || intersectRight(p_circleMid, p_radius, p_rectTopLeft,
                        p_rectSize);
    }

    bool CollisionDetector::intersectTop(const Vec2f& p_circleMid,
            const float p_radius, const Vec2f& p_rectTopLeft,
            const Vec2f& p_rectSize)
    {
        return ((fabs(p_rectTopLeft.y - p_circleMid.y) <= p_radius
                && (fabs(p_rectTopLeft.x - p_circleMid.x) <= p_radius
                        || fabs(p_rectTopLeft.x + p_rectSize.x - p_circleMid.x)
                                <= p_radius)));
    }

    bool CollisionDetector::intersectBot(const Vec2f& p_circleMid,
            const float p_radius, const Vec2f& p_rectTopLeft,
            const Vec2f& p_rectSize)
    {
        return ((fabs(p_rectTopLeft.y - p_rectSize.y - p_circleMid.y)
                <= p_radius
                && (fabs(p_rectTopLeft.x - p_circleMid.x) <= p_radius
                        || fabs(p_rectTopLeft.x + p_rectSize.x - p_circleMid.x)
                                <= p_radius)));
    }

    bool CollisionDetector::intersectLeft(const Vec2f& p_circleMid,
            const float p_radius, const Vec2f& p_rectTopLeft,
            const Vec2f& p_rectSize)
    {
        return ((fabs(p_rectTopLeft.x - p_circleMid.x) <= p_radius
                && (fabs(p_rectTopLeft.y - p_circleMid.y) <= p_radius
                        || fabs(p_rectTopLeft.y - p_rectSize.y - p_circleMid.y)
                                <= p_radius)));
    }

    bool CollisionDetector::intersectRight(const Vec2f& p_circleMid,
            const float p_radius, const Vec2f& p_rectTopLeft,
            const Vec2f& p_rectSize)
    {
        return ((fabs(p_rectTopLeft.x + p_rectSize.x - p_circleMid.x)
                <= p_radius
                && (fabs(p_rectTopLeft.y - p_circleMid.y) <= p_radius
                        || fabs(p_rectTopLeft.y - p_rectSize.y - p_circleMid.y)
                                <= p_radius)));
    }
}
