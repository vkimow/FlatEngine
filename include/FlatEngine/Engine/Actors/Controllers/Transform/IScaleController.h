#pragma once

#include "FlatEngine/Core/Main/FlatEngineApi.h"
#include "SFML/System.hpp"

namespace Flat::Engine::Actors
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