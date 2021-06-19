#pragma once

#include "Core/Main/FlatEngineApi.h"
#include "Controllers/Transform/IMoveController.h"
#include "Controllers/Transform/IRotateController.h"
#include "Controllers/Camera/IZoomController.h"

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