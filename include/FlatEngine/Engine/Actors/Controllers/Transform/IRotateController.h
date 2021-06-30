#pragma once

#include "FlatEngine/Core/Main/FlatEngineApi.h"

namespace Flat::Engine::Actors
{
	class FLAT_ENGINE_API IRotateController
	{
	public:
		virtual float GetSpeed() const = 0;
		virtual void SetSpeed(float value) = 0;

	protected:
		virtual void Rotate(float delta) = 0;
	};
}