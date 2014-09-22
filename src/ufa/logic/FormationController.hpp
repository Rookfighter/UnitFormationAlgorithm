#ifndef UFA_FORMATION_CONTROLLER_HPP
#define UFA_FORMATION_CONTROLLER_HPP

#include "ufa/entities/Formation.hpp"
#include "ufa/logic/Controller.hpp"
#include "ufa/logic/FormationShape.hpp"

namespace ufa
{

	class FormationController : public Controller
	{
	private:
		void formFormation(const unsigned int p_usec);
		bool hasFormedUp();
		void moveFormation(const unsigned int p_usec);
		
		void selectCommander();
		bool reachedTarget();
		void updateFormationOrientation();
		void updateFormationCenter(const Vec2 &p_commanderPosition);
		void setUnitTargetPositions();
		void calcCommanderVelocity(const unsigned int p_usec);
	protected:
		Formation formation_;
		FormationShape *formationShape_;

	public:
		FormationController(const std::vector<std::shared_ptr<Unit>> &p_units,
		                    FormationShape *p_formationShape);
		virtual ~FormationController();

		Formation& getFormation();

		void moveTo(const Vec2& p_targetPosition);
		void formUpAt(const Vec2 &p_position);

		void step(const unsigned int p_usec);


	};

}

#endif
