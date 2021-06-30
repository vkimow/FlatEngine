#pragma once

#include "FlatEngine/Core/Main/FlatEngineApi.h"

namespace Flat::Engine::Actors
{
	class FLAT_ENGINE_API IZoomController
	{
		virtual float GetSpeed() const = 0;
		virtual void SetSpeed(float value) = 0;

	protected:
		virtual void Zoom(float delta) = 0;
	};
}