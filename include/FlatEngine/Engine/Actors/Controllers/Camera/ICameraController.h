#pragma once

#include "FlatEngine/Core/Main/FlatEngineApi.h"
#include "FlatEngine/Engine/Actors/Controllers/Transform/IMoveController.h"
#include "FlatEngine/Engine/Actors/Controllers/Transform/IRotateController.h"
#include "FlatEngine/Engine/Actors/Controllers/Camera/IZoomController.h"

namespace Flat::Engine::Actors
{
	class FLAT_ENGINE_API ICameraController
	{
	public:
		virtual IMoveController& GetMoveController() = 0;
		virtual IRotateController& GetRotateController() = 0;
		virtual IZoomController& GetZoomController() = 0;
	};
}