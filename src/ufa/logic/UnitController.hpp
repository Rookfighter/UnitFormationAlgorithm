#ifndef UFA_UNIT_CONTROLLER_HPP
#define UFA_UNIT_CONTROLLER_HPP

#include <memory>
#include "ufa/logic/Controller.hpp"
#include "ufa/entities/World.hpp"

namespace ufa
{
	class UnitController : public Controller
	{
	private:
		World &world_;
		std::shared_ptr<Unit> unit_;
		
		void setVelocityOfUnit(const unsigned int p_usec);
		void moveUnit(const unsigned int p_usec);
	public:
		UnitController(World &p_world);
		~UnitController();
		
		void step(const unsigned int p_usec);
		void setTarget(const Vec2 &p_target);
		
		std::shared_ptr<Unit>& getUnit();
	};

}

#endif
