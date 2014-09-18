#ifndef UFA_FORMATION_CONTROLLER_HPP
#define UFA_FORMATION_CONTROLLER_HPP

#include "ufa/entities/Formation.hpp"
#include "ufa/logic/Controller.hpp"
#include "ufa/logic/FormationShape.hpp"
#include "ufa/logic/FormationPlacement.hpp"

namespace ufa
{

	class FormationController : public Controller
	{
	private:
		void setUnitTargetPositions();

		void formFormation(const unsigned int p_usec);
		void moveFormation(const unsigned int p_usec);
	protected:
		Formation formation_;
		FormationShape *formationShape_;
		FormationPlacement *formationPlacement_;

	public:
		FormationController(const std::vector<std::shared_ptr<Unit>> &p_units,
		                    FormationShape *p_formationShape,
							FormationPlacement *p_formationPlacement);
		virtual ~FormationController();

		Formation& getFormation();

		void moveTo(const Vec2& p_targetPosition);
		void formUpAt(const Vec2 &p_position);

		void step(const unsigned int p_usec);


	};

}

#endif
