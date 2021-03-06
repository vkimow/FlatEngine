#pragma once

#include "FlatEngine/Core/Main/FlatEngineApi.h"
#include "SFML\System.hpp"

namespace Flat::Core
{
	class FLAT_ENGINE_API ScreenSettings
	{
	public:
		ScreenSettings(unsigned int W, unsigned int H);
		ScreenSettings() = delete;

		~ScreenSettings() {};

	public:
		sf::Vector2u GetResolution() const { return resoultion; }
		sf::Vector2f GetHalfResolution() const { return halfResoultion; }

	private:
		sf::Vector2u resoultion;
		sf::Vector2f halfResoultion;
	};
}