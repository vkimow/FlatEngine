#include "FlatEngine/Core/Display/Tools/ScreenSettings.h"


namespace Flat::Core
{
	ScreenSettings::ScreenSettings(unsigned int W, unsigned int H)
	{
		resoultion = sf::Vector2u(W, H);
		halfResoultion = sf::Vector2f(W / 2, H / 2);
	}
}