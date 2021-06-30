#pragma once

#include "FlatEngine/Core/Main/FlatEngineApi.h"
#include "SFML/System.hpp"

namespace Flat::Core
{
	class FLAT_ENGINE_API IMovable
	{
	public:
		virtual void Move(const sf::Vector2f& delta) = 0;
		virtual void SetPosition(const sf::Vector2f& value) = 0;
		virtual sf::Vector2f GetPosition() const = 0;
	};
}