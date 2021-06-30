#include "FlatEngine/Core/Input/Elements/Press/PressableMouse.h"

namespace Flat::Core::Input
{
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