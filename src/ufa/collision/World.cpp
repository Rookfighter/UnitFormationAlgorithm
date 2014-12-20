#include <cassert>
#include "ufa/collision/World.hpp"

namespace collision
{

	World::World(const Vec2i &p_size, const Vec2f &p_tileSize)
	:front_(NULL), tail_(NULL), size_(p_size), tileSize_(p_tileSize)
	{
		assert(size_.x >= 0 && size_.y >= 0);
		tileGrid_ = new CollisionTile**[size_.x];
		for(int i = 0; i < size_.x; ++i) {
			tileGrid_[i] = new CollisionTile*[size_.y];
			for(int j = 0; j < size_.y; ++j)
				tileGrid_[i][j] = NULL;
		}
		
	}

	World::~World()
	{
	}

	CollisionObject* World::createCollisionObject()
	{
		CollisionObject* result = new CollisionObject();
		if(front_ == NULL) {
			front_ = result;
			tail_ = result;
		} else {
			tail_ = result;
		}
		
		result->setGridTileSize(tileSize_);
		return result;
	}
	
	bool World::destroyCollisionObject(CollisionObject* p_object)
	{
		return false;
	}
	
	CollisionTile* World::createCollisionTile(const Vec2i& p_position)
	{
		if(tileGrid_[p_position.x][p_position.y] != NULL)
			return NULL;
		
		tileGrid_[p_position.x][p_position.y] = new CollisionTile(p_position);
		tileGrid_[p_position.x][p_position.y]->setTileSize(tileSize_);
		return tileGrid_[p_position.x][p_position.y];
	}
	
	bool World::destroyCollisionTile(const Vec2i& p_position)
	{
		if(tileGrid_[p_position.x][p_position.y] == NULL)
			return false;
			
		delete tileGrid_[p_position.x][p_position.y];
		tileGrid_[p_position.x][p_position.y] = NULL;
		
		return true;
	}
}
