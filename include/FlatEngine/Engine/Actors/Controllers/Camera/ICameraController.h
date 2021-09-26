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
		virtual std::shared_ptr<IMoveController> GetMoveController() = 0;
		virtual std::shared_ptr<IRotateController> GetRotateController() = 0;
		virtual std::shared_ptr<IZoomController> GetZoomController() = 0;
	};
}