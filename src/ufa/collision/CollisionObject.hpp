#ifndef COLLISION_COLLISION_OBJECT_HPP
#define COLLISION_COLLISION_OBJECT_HPP

#include "ufa/collision/Vec2f.hpp"
#include "ufa/collision/Vec2i.hpp"

namespace collision
{
	class CollisionObject
	{
	private:
		Vec2f position_;
		Vec2f velocity_;
		Vec2f tileSize_;
		
		float radius_;
		
		void *userData_;
	public:
		CollisionObject();
		~CollisionObject();
		
		void setPosition(const Vec2f &p_position);
		void setVelocity(const Vec2f &p_velocity);
		void setRadius(const float p_radius);
		void setUserData(void *p_userData);
		void setGridTileSize(const Vec2f &p_size);
		
		const Vec2f& getPosition() const;
		const Vec2f& getVelocity() const;
		float getRadius() const;
		void* getUserData();
		Vec2i getGridPosition() const;
		
	};

}

#endif
