#ifndef UFA_UNIT_DRAWER_HPP
#define UFA_UNIT_DRAWER_HPP

#include <memory>
#include <list>
#include "ufa/ui/Drawable.hpp"
#include "ufa/ui/DrawableUnit.hpp"

namespace ufa
{
	class UnitDrawer: public Drawable
	{
	private:
		std::list<std::shared_ptr<DrawableUnit>> units_;
	public:
		UnitDrawer();
		~UnitDrawer();
		
		void draw(sf::RenderTarget &p_renderTarget);
		
		void addUnit(const std::shared_ptr<DrawableUnit> &p_unit);
		void clearUnits();
		
		std::list<std::shared_ptr<DrawableUnit>> getUnitsInRect(const sf::Vector2f &p_topLeft, const sf::Vector2f &p_size);
	};

}

#endif // UFA_UNIT_DRAWER_HPP
