#pragma once

#include "FlatEngineApi.h"
#include "SFML\System.hpp"

namespace FlatEngine::Core::Simulation
{
	class FLAT_ENGINE_API IMovable
	{
	public:
		virtual void Move(const sf::Vector2f& delta) = 0;
		virtual void SetPosition(const sf::Vector2f& value) = 0;
		virtual sf::Vector2f GetPosition() const = 0;
	};
}