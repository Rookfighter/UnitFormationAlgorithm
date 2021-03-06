#ifndef UFA_DRAWABLE_UNIT_HPP
#define UFA_DRAWABLE_UNIT_HPP

#include <memory>
#include "ui/Drawable.hpp"
#include "logic/UnitController.hpp"

namespace ufa
{
	/* DrawableUnit represents the visualization of an Unit. */
	class DrawableUnit: public Drawable
	{
	private:
		std::shared_ptr<UnitController> unitController_;
		sf::Vector2f position_;
		bool selected_;
		sf::Color unitColor_;
		
		void updatePosition();
		void drawTarget(sf::RenderTarget &p_renderTarget);
		void drawUnit(sf::RenderTarget &p_renderTarget);
		void drawSelection(const sf::Vector2f &p_position, const sf::Vector2f &p_size, sf::RenderTarget &p_renderTarget);
	public:
		DrawableUnit(const std::shared_ptr<UnitController> &p_unitController, const sf::Color p_unitcolor);
		virtual ~DrawableUnit();
		
		void draw(sf::RenderTarget &p_renderTarget);
		void select(const bool p_selected);
		bool isSelected();
		
		sf::Vector2f position();
		std::shared_ptr<UnitController>& getUnitController();
	};

}

#endif
