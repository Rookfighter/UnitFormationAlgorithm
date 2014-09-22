#ifndef UFA_FORMATION_HPP
#define UFA_FORMATION_HPP

#include <memory>
#include <vector>
#include "ufa/entities/Unit.hpp"

namespace ufa
{
	enum FormationState {BROKEN, FORMING, FORMED};
	
	class FormationUnit
	{
	public:
		std::shared_ptr<Unit> unit;
		Vec2 position;
	};
	
	class Formation
	{
	public:
		Vec2 center;
		Vec2 targetPosition;
		bool moving;
		float orientation;
		
		FormationUnit commander;
		std::vector<FormationUnit> units;
		
		FormationState state;
		
		Formation();
		~Formation();
		
		bool reachedTarget(const float p_epsilon) const;

	};

}

#endif
