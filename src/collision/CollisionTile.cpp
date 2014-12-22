#include <cstddef>
#include <cassert>
#include "collision/CollisionTile.hpp"

namespace collision
{

    CollisionTile::CollisionTile(const Vec2i& p_position)
            : isObstacle_(false), userData_(NULL), fineGrainedArea_(), gridPosition_(
                    p_position), tileSize_(1, 1)
    {
    }

    CollisionTile::~CollisionTile()
    {
    }

    void CollisionTile::initFineGrainedArea()
    {
        fineGrainedArea_.resize(GRANULARITY);
        for(unsigned int x = 0; x < fineGrainedArea_.size(); ++x) {
            fineGrainedArea_[x].resize(GRANULARITY);
            for(unsigned int y = 0; y < fineGrainedArea_[x].size(); ++y)
                fineGrainedArea_[x][y] = false;
        }
    }

    void CollisionTile::setIsObstalce(const bool p_isObstacle)
    {
        isObstacle_ = p_isObstacle;
        if(!isObstacle_)
            fineGrainedArea_.clear();
    }

    void CollisionTile::setIsFineGrained(const bool p_isFineGrained)
    {
        if(p_isFineGrained)
            if(!isFineGrained())
                initFineGrainedArea();
            else
                fineGrainedArea_.clear();
    }

    void CollisionTile::setFineGrainedTile(const int x, const int y,
            const bool p_tileIsObstalce)
    {
        assert(isFineGrained());
        fineGrainedArea_[x][y] = p_tileIsObstalce;
    }

    void CollisionTile::setTileSize(const Vec2f &p_size)
    {
        assert(p_size.x > 0 && p_size.y > 0);
        tileSize_ = p_size;
    }

    void CollisionTile::setUserData(void *p_userData)
    {
        userData_ = p_userData;
    }

    const Vec2i& CollisionTile::getGridPosition() const
    {
        return gridPosition_;
    }

    Vec2f CollisionTile::getPosition() const
    {
        Vec2f result;
        result.x = tileSize_.x / 2 + tileSize_.x * gridPosition_.x;
        result.y = tileSize_.y / 2 + tileSize_.y * gridPosition_.y;
        return result;
    }

    const Vec2f& CollisionTile::getTileSize() const
    {
        return tileSize_;
    }

    bool CollisionTile::isObstacle() const
    {
        return isObstacle_;
    }

    bool CollisionTile::isFineGrained() const
    {
        return !fineGrainedArea_.empty();
    }

    bool CollisionTile::getFineGrainedTile(const int x, const int y) const
    {
        assert(isFineGrained());
        return fineGrainedArea_[x][y];
    }

    void CollisionTile::getFineGrainedRects(std::vector<Rectangle> &p_tileRects) const
    {
        assert(isFineGrained());

        Rectangle rect = getRect();
        Vec2f finegrainedSize = rect.getSize() / GRANULARITY;

        p_tileRects.resize(GRANULARITY * GRANULARITY);
        for(unsigned int i = 0; i < p_tileRects.size(); ++i) {
            Vec2f currentCenter;
            unsigned int x = i / GRANULARITY;
            unsigned int y = i % GRANULARITY;
            currentCenter.x = rect.getTopLeft().x + finegrainedSize.x / 2 + finegrainedSize.x * x;
            currentCenter.y = rect.getTopLeft().y + finegrainedSize.y / 2 + finegrainedSize.y * y;
            p_tileRects[x] = Rectangle(currentCenter, finegrainedSize);
        }
    }

    unsigned int CollisionTile::getGranularity() const
    {
        return GRANULARITY;
    }

    void* CollisionTile::getUserData()
    {
        return userData_;
    }

    Rectangle CollisionTile::getRect() const
    {
        return Rectangle(getPosition(), tileSize_);
    }

}
