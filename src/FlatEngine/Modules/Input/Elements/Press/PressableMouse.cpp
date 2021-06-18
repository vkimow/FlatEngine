#include "PressableMouse.h"
#include "SFML\System.hpp"

namespace FlatEngine::Core::Modules::Input{

PressableMouse::PressableMouse(sf::Mouse::Button button)
	:
	button(button)
{}

PressableMouse::~PressableMouse() {}

bool PressableMouse::GetPressInput(const sf::Event& event)
{
	return sf::Mouse::isButtonPressed(button);
}

}