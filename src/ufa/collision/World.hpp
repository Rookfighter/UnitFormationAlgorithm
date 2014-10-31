#ifndef COLLISION_WORLD_HPP
#define COLLISION_WORLD_HPP

#include "ufa/collision/CollisionObject.hpp"
#include "ufa/collision/CollisionTile.hpp"

namespace collision
{

	class World
	{
	private:
		CollisionObject *front_;
		CollisionObject *tail_;
		
		CollisionTile ***tileGrid_;
		Vec2i size_;
		Vec2f tileSize_;
	public:
		World(const Vec2i &p_size, const Vec2f &p_tileSize);
		~World();
		
		CollisionObject* createCollisionObject();
		bool destroyCollisionObject(CollisionObject* p_object);
		
		CollisionTile* createCollisionTile(const Vec2i& p_position);
		bool destroyCollisionTile(const Vec2i& p_position);
	};

}

#endif
