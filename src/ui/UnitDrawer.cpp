#include "ui/UnitDrawer.hpp"

namespace ufa
{

	UnitDrawer::UnitDrawer()
	{
	}

	UnitDrawer::~UnitDrawer()
	{
	}
	
	void UnitDrawer::draw(sf::RenderTarget &p_renderTarget)
	{
		std::list<std::shared_ptr<DrawableUnit>>::iterator it;
		
		for(it = units_.begin(); it != units_.end(); ++it)
			(*it)->draw(p_renderTarget);
	}
		
	void UnitDrawer::addUnit(const std::shared_ptr<DrawableUnit> &p_unit)
	{
		units_.push_back(p_unit);
	}
	
	void UnitDrawer::clearUnits()
	{
		units_.clear();
	}
	
	std::list<std::shared_ptr<DrawableUnit>> UnitDrawer::getUnitsInRect(const sf::Vector2f &p_topLeft, const sf::Vector2f &p_size)
	{
		std::list<std::shared_ptr<DrawableUnit>> result;
		std::list<std::shared_ptr<DrawableUnit>>::iterator it;
		for(it = units_.begin(); it != units_.end(); ++it) {
			std::shared_ptr<DrawableUnit> currentUnit = *it;
			if(currentUnit->position().x > p_topLeft.x && currentUnit->position().y > p_topLeft.y &&
			   currentUnit->position().x < p_topLeft.x + p_size.x && currentUnit->position().y < p_topLeft.y + p_size.y)
				   result.push_back(currentUnit);
		}
		
		return result;
	}
}

