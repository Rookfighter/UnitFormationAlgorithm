#include <cstddef>
#include <cassert>
#include "ufa/collision/CollisionTile.hpp"

namespace collision
{

	CollisionTile::CollisionTile(const Vec2i& p_position)
		:isObstacle_(false), userData_(NULL), fineGrainedArea_(NULL),
		position_(p_position), gridTileSize_(1,1)
	{
	}

	CollisionTile::CollisionTile(const CollisionTile &p_tile)
	{
		isObstacle_ = p_tile.isObstacle_;
		userData_ = p_tile.userData_;
		
		if(p_tile.isFineGrained()) {
			initFineGrainedArea();
			for(int i = 0; i < GRANULARITY; ++i)
				for(int j = 0; j < GRANULARITY; ++j)
					fineGrainedArea_[i][j] = p_tile.fineGrainedArea_[i][j];
		} else 
			cleanup();
	}

	CollisionTile::~CollisionTile()
	{
		cleanup();
	}

	void CollisionTile::initFineGrainedArea()
	{
		if(!isFineGrained()) {
			fineGrainedArea_ = new bool*[GRANULARITY];
			for(int i = 0; i < GRANULARITY; ++i) {
				fineGrainedArea_[i] = new bool[GRANULARITY];
				for(int j = 0; j < GRANULARITY ; ++j)
					fineGrainedArea_[i][j] = false;
			}
		}
	}
	
	void CollisionTile::cleanup()
	{
		if(isFineGrained()) {
			for(int i = 0; i < GRANULARITY; ++i)
				delete[] fineGrainedArea_[i];
		}
		delete[] fineGrainedArea_;
		fineGrainedArea_ = NULL;
	}

	void CollisionTile::setIsObstalce(const bool p_isObstacle)
	{
		isObstacle_ = p_isObstacle;
		if(!isObstacle_)
			cleanup();
	}

	void CollisionTile::setIsFineGrained(const bool p_isFineGrained)
	{
		if(p_isFineGrained)
			initFineGrainedArea();
		else
			cleanup();
	}

	void CollisionTile::setFineGrainedAreaTile(const int x, const int y, const bool p_tileIsObstalce)
	{
		assert(isFineGrained());
		fineGrainedArea_[x][y] = p_tileIsObstalce;
	}
	
	void CollisionTile::setGridTileSize(const Vec2f &p_size)
	{
		gridTileSize_ = p_size;
	}

	void CollisionTile::setUserData(void *p_userData)
	{
		userData_ = p_userData;
	}
	
	const Vec2i& CollisionTile::getPosition() const
	{
		return position_;
	}
	
	Vec2f CollisionTile::getRealPosition() const
	{
		Vec2f result;
		result.x = gridTileSize_.x / 2 + position_.x * gridTileSize_.x;
		result.y = gridTileSize_.y / 2 + position_.y * gridTileSize_.y;
		
		return result;
	}
	
	bool CollisionTile::isObstacle() const
	{
		return isObstacle_;
	}

	bool CollisionTile::isFineGrained() const
	{
		return fineGrainedArea_ != NULL;
	}

	bool CollisionTile::getFineGrainedAreaTile(const int x, const int y) const
	{
		assert(isFineGrained());
		return fineGrainedArea_[x][y];
	}

	int CollisionTile::getGranularity() const
	{
		return GRANULARITY;
	}

	void* CollisionTile::getUserData()
	{
		return userData_;
	}

}
