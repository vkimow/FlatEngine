#pragma once

#include "FlatEngine/Core/Main/FlatEngineApi.h"
#include "FlatEngine/Core/Transform/IMovable.h"
#include "FlatEngine/Core/Transform/IRotatable.h"
#include "FlatEngine/Core/Transform/IScalable.h"
#include "SFML/System.hpp"


namespace Flat::Core
{
	class FLAT_ENGINE_API ITransformable : public IMovable, public IRotatable, public IScalable
	{
		friend std::ostream& operator<<(std::ostream& out, const ITransformable& transformable);
	};
}