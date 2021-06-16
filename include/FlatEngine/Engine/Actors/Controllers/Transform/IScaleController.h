#pragma once

#include <Core.h>
#include "SFML/System.hpp"

namespace FlatEngine::Actors::Controllers
{
	class FLAT_ENGINE_API IScaleController
	{
	public:
		virtual float GetSpeed() const = 0;
		virtual void SetSpeed(float value) = 0;

	protected:
		virtual void Scale(const sf::Vector2f& delta) = 0;
	};
}