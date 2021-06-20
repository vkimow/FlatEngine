#include "Elements/Press/PressableMouse.h"

namespace FlatEngine::Input{

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