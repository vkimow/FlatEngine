#include "Elements/Press/PressableKey.h"

namespace FlatEngine::Input
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