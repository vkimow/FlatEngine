#pragma once

#include "Main/FlatEngineApi.h"
#include "Transform/IMovable.h"
#include "Transform/IRotatable.h"
#include "Transform/IScalable.h"
#include "SFML/System.hpp"


namespace FlatEngine::Core
{
	class FLAT_ENGINE_API ITransformable : public IMovable, public IRotatable, public IScalable
	{
		friend std::ostream& operator<<(std::ostream& out, const ITransformable& transformable);
	};
}