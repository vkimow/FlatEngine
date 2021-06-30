#pragma once

#include "FlatEngine/Core/Main/FlatEngineApi.h"

namespace Flat::Core
{
	class FLAT_ENGINE_API IRotatable
	{
	public:
		virtual void Rotate(float delta) = 0;
		virtual void SetRotation(float value) = 0;
		virtual float GetRotation() const = 0;
	};
}