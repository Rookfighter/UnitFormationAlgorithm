#ifndef COLLISION_COLLISION_TILE_HPP
#define COLLISION_COLLISION_TILE_HPP

#include "ufa/collision/Vec2i.hpp"
#include "ufa/collision/Vec2f.hpp"

namespace collision
{
	class CollisionTile
	{
	private:
		static const int GRANULARITY = 4;
		
		Vec2i position_;
		Vec2f gridTileSize_;
		
		bool isObstacle_;
		bool **fineGrainedArea_;
		
		void *userData_;
		
		void initFineGrainedArea();
		void cleanup();
	public:
		CollisionTile(const Vec2i& p_position);
		CollisionTile(const CollisionTile &p_tile);
		~CollisionTile();
		
		void setIsObstalce(const bool p_isObstacle);
		void setIsFineGrained(const bool p_isFineGrained);
		void setFineGrainedAreaTile(const int x, const int y, const bool p_tileIsObstalce);
		void setGridTileSize(const Vec2f &p_size);
		void setUserData(void *p_userData);
		
		const Vec2i& getPosition() const;
		Vec2f getRealPosition() const;
		bool isObstacle() const;
		bool isFineGrained() const;
		bool getFineGrainedAreaTile(const int x, const int y) const;
		int getGranularity() const;
		void* getUserData();

	};

}

#endif
