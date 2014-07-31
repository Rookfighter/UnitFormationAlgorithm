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
		std::shared_ptr<World> world_;
		
		void setVelocityOfUnits();
		void moveUnits(const unsigned int p_usec);
	public:
		UnitController(const std::shared_ptr<World> &p_world);
		~UnitController();
		
		void step(const unsigned int p_usec);
	};

}

#endif
