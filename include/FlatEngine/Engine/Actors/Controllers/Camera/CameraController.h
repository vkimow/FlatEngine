#pragma once

#include "FlatEngineApi.h"
#include "Modules\Display\Camera\Camera.h"
#include "Modules\Update\UpdateElement.h"
#include "Modules\Input\InputHeader.h"
#include "Controllers/Transform/MoveController.h"
#include "Controllers/Transform/RotateController.h"
#include "ICameraController.h"
#include "ZoomController.h"


namespace FlatEngine::Actors::Controllers
{
	class FLAT_ENGINE_API CameraController : public ICameraController, public Core::Modules::UpdateElement
	{
	public:
		CameraController(Core::Modules::Display::Camera* camera,
						 std::shared_ptr<Core::Modules::Input::Vector> moveInput,
						 std::shared_ptr<Core::Modules::Input::Delta> rotateInput,
						 std::shared_ptr<Core::Modules::Input::Delta> zoomInput);



		~CameraController();

	public:
		virtual void Update() override;

	public:
		virtual IMoveController& GetMoveController() override;
		virtual IRotateController& GetRotateController() override;
		virtual IZoomController& GetZoomController() override;

	private:
		Core::Modules::Display::Camera* camera;

		MoveController move;
		RotateController rotate;
		ZoomController zoom;
	};
}