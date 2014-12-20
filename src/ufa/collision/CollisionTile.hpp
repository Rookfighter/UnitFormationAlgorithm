#ifndef COLLISION_COLLISION_TILE_HPP
#define COLLISION_COLLISION_TILE_HPP

#include <vector>
#include "ufa/collision/Vec2i.hpp"
#include "ufa/collision/Vec2f.hpp"

namespace collision
{
	class CollisionTile
	{
	private:
		static const unsigned int GRANULARITY = 4;
		
		Vec2i position_;
		Vec2f tileSize_;
		
		bool isObstacle_;
		std::vector<std::vector<bool>> fineGrainedArea_;
		
		void *userData_;
		
		void initFineGrainedArea();
	public:
		CollisionTile(const Vec2i& p_position);
		~CollisionTile();
		
		void setIsObstalce(const bool p_isObstacle);
		void setIsFineGrained(const bool p_isFineGrained);
		void setFineGrainedAreaTile(const int x, const int y, const bool p_tileIsObstalce);
		void setTileSize(const Vec2f &p_size);
		void setUserData(void *p_userData);
		
		const Vec2i& getGridPosition() const;
		Vec2f getTopLeft() const;
		Vec2f getPosition() const;
		const Vec2f& getTileSize() const;
		bool isObstacle() const;
		bool isFineGrained() const;
		bool getFineGrainedAreaTile(const int x, const int y) const;
		unsigned int getGranularity() const;
		void* getUserData();
		std::vector<Vec2f> getCorners() const;
	};

}

#endif
