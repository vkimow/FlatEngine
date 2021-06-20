#pragma once

#include "Core/FlatEngineApi.h"
#include "IMovable.h"
#include "IRotatable.h"
#include "IScalable.h"
#include "SFML/System.hpp"


namespace FlatEngine::Core
{
	class FLAT_ENGINE_API ITransformable : public IMovable, public IRotatable, public IScalable
	{
		friend std::ostream& operator<<(std::ostream& out, const ITransformable& transformable);
	};
}