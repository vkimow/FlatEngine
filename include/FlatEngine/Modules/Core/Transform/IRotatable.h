#pragma once

#include "Main/FlatEngineApi.h"

namespace FlatEngine::Core
{
	class FLAT_ENGINE_API IRotatable
	{
	public:
		virtual void Rotate(float delta) = 0;
		virtual void SetRotation(float value) = 0;
		virtual float GetRotation() const = 0;
	};
}