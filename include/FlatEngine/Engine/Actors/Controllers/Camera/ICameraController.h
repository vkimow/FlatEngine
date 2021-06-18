#pragma once

#include "FlatEngineApi.h"
#include "Actors/Controllers/Transform/MoveController.h"
#include "Actors/Controllers/Transform/RotateController.h"
#include "ZoomController.h"

namespace FlatEngine::Actors::Controllers
{
	class FLAT_ENGINE_API ICameraController
	{
	public:
		virtual IMoveController& GetMoveController() = 0;
		virtual IRotateController& GetRotateController() = 0;
		virtual IZoomController& GetZoomController() = 0;
	};
}