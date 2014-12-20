#include <cstddef>
#include <cassert>
#include "ufa/collision/CollisionTile.hpp"

namespace collision
{

	CollisionTile::CollisionTile(const Vec2i& p_position)
		:isObstacle_(false), userData_(NULL), fineGrainedArea_(),
		position_(p_position), tileSize_(1,1)
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

	void CollisionTile::setFineGrainedAreaTile(const int x, const int y, const bool p_tileIsObstalce)
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
		return position_;
	}
	
	Vec2f CollisionTile::getTopLeft() const
	{
	    Vec2f result;
	    result.x = position_.x * tileSize_.x;
	    result.y = position_.y * tileSize_.y;

	    return result;
	}

	Vec2f CollisionTile::getPosition() const
	{
		Vec2f result = getTopLeft();
		result.x += tileSize_.x / 2;
		result.y += tileSize_.y / 2;
		
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

	bool CollisionTile::getFineGrainedAreaTile(const int x, const int y) const
	{
		assert(isFineGrained());
		return fineGrainedArea_[x][y];
	}

	unsigned int CollisionTile::getGranularity() const
	{
		return GRANULARITY;
	}

	void* CollisionTile::getUserData()
	{
		return userData_;
	}

}
