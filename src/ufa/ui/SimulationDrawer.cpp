#include "ufa/ui/SimulationDrawer.hpp"
#include "ufa/ui/DrawEvent.hpp"
#define SIZE_FACTOR 30

namespace ufa
{

	SimulationDrawer::SimulationDrawer(const std::shared_ptr<World> &p_world)
	: world_(p_world)
	{	}

	SimulationDrawer::~SimulationDrawer()
	{	}
	
	void SimulationDrawer::drawSimulation(sf::RenderTarget &p_renderTarget)
	{
		drawDrawObjects(p_renderTarget);
		// create a texture on which the hud will be drawn
		// so SFML Views don't have to be considered
		hud.create(p_renderTarget.getSize().x, p_renderTarget.getSize().y);
		hud.clear(sf::Color::Transparent);
		drawHudElements(hud);
		hud.display();
		sf::Sprite hudSprite(hud.getTexture());
		// set the position of the hudSprite to the top left corner
		int x = p_renderTarget.getView().getCenter().x - (p_renderTarget.getSize().x / 2);
		int y = p_renderTarget.getView().getCenter().y - (p_renderTarget.getSize().y / 2);
		hudSprite.setPosition(x, y);
		
		// draw the hud on the given RenderTarget
		p_renderTarget.draw(hudSprite);
	}
	
	void SimulationDrawer::drawDrawObjects(sf::RenderTarget &p_renderTarget)
	{
		DrawEvent event(p_renderTarget);
		event.sizeFactor = SIZE_FACTOR;
		
		std::list<std::shared_ptr<Drawable>>::iterator it;
		for(it = drawObjects.begin(); it != drawObjects.end(); ++it)
			(*it)->draw(event);
	}
	
	void SimulationDrawer::drawHudElements(sf::RenderTarget &p_renderTarget)
	{
		DrawEvent event(p_renderTarget);
		event.sizeFactor = SIZE_FACTOR;
		
		std::list<std::shared_ptr<Drawable>>::iterator it;
		for(it = hudElements.begin(); it != hudElements.end(); ++it)
			(*it)->draw(event);
	}
	
	std::list<std::shared_ptr<Drawable>> SimulationDrawer::getObjectsInRect(
					const sf::Vector2f &p_topLeft,
					const sf::Vector2f &p_size)
	{
		std::list<std::shared_ptr<Drawable>> result;
		std::list<std::shared_ptr<Drawable>>::iterator it;
		for(it = drawObjects.begin(); it != drawObjects.end(); ++it) {
			std::shared_ptr<Drawable> currentDrawable = *it;
			if(currentDrawable->position.x > p_topLeft.x && currentDrawable->position.y > p_topLeft.y &&
			   currentDrawable->position.x < p_topLeft.x + p_size.x && currentDrawable->position.y < p_topLeft.y + p_size.y)
				   result.push_back(currentDrawable);
		}
		
		return result;
	}
}

