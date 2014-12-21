#ifndef UFA_WORLD_HPP
#define UFA_WORLD_HPP

#include <list>
#include <memory>
#include "entities/Unit.hpp"

namespace ufa
{
	class World
	{
	public:
		std::list<std::shared_ptr<Unit>> units;
		
		World();
		~World();
		
	};

}

#endif
