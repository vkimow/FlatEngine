#include "VectorMouse.h"

namespace FlatEngine::Core::Modules::Input{

VectorMouse::VectorMouse()
{}

sf::Vector2f VectorMouse::GetVectorInput(const sf::Event& event)
{
	sf::Vector2i newMousePosInt = sf::Mouse::getPosition();
	sf::Vector2f oldMousePos = mousePosition;
	mousePosition = sf::Vector2f((float)newMousePosInt.x, (float)newMousePosInt.y);

	return sf::Vector2f(mousePosition.x - oldMousePos.x, mousePosition.y - oldMousePos.y);
}

}