#pragma once

#include "Core/FlatEngineApi.h"
#include "Display\Camera\Camera.h"
#include "Core/Main/Update/UpdateElement.h"
#include "Input\Elements/Delta\Delta.h"
#include "Input/Elements/Vector/Vector.h"
#include "Controllers/Transform/MoveController.h"
#include "Controllers/Transform/RotateController.h"
#include "Controllers/Camera/ICameraController.h"
#include "Controllers/Camera/ZoomController.h"


namespace FlatEngine::Actors::Controllers
{
	class FLAT_ENGINE_API CameraController : public ICameraController, public Core::UpdateElement
	{
	public:
		CameraController(Display::Camera* camera,
						 std::shared_ptr<Input::Vector> moveInput,
						 std::shared_ptr<Input::Delta> rotateInput,
						 std::shared_ptr<Input::Delta> zoomInput);



		~CameraController();

	public:
		virtual void Update() override;

	public:
		virtual IMoveController& GetMoveController() override;
		virtual IRotateController& GetRotateController() override;
		virtual IZoomController& GetZoomController() override;

	private:
		Display::Camera* camera;

		MoveController move;
		RotateController rotate;
		ZoomController zoom;
	};
}