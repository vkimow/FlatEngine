#include "PressableKey.h"
#include "SFML\System.hpp"

namespace FlatEngine::Core::Modules::Input
{
	PressableKey::PressableKey(sf::Keyboard::Key key)
		:
		key(key)
	{}

	PressableKey::~PressableKey()
	{}

	bool PressableKey::GetPressInput(const sf::Event& event)
	{
		return sf::Keyboard::isKeyPressed(key);
	}
}