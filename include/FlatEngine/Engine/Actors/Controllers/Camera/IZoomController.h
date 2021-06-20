#pragma once

#include "Core/FlatEngineApi.h"

namespace FlatEngine::Actors::Controllers
{
	class FLAT_ENGINE_API IZoomController
	{
		virtual float GetSpeed() const = 0;
		virtual void SetSpeed(float value) = 0;

	protected:
		virtual void Zoom(float delta) = 0;
	};
}