#ifndef UFA_UNIT_CONTROLLER_HPP
#define UFA_UNIT_CONTROLLER_HPP

#include <memory>
#include "logic/Controller.hpp"
#include "entities/World.hpp"

namespace ufa
{
	class UnitController : public Controller
	{
	private:
		World &world_;
		std::shared_ptr<Unit> unit_;
		
		void setVelocityOfUnit(const unsigned int p_usec);
	public:
		UnitController(const std::shared_ptr<Unit> &p_unit, World &p_world);
		~UnitController();
		
		void step(const unsigned int p_usec);
		
		std::shared_ptr<Unit>& getUnit();
	};

}

#endif
