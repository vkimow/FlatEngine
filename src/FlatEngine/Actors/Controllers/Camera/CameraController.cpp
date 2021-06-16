#include "CameraController.h"

#include "Tools\ToolsHeader.h"
#include <functional>

namespace FlatEngine::Actors::Controllers
{
	CameraController::CameraController(Core::Modules::Display::Camera* camera,
									   std::shared_ptr<Core::Modules::Input::Vector> moveInput = nullptr,
									   std::shared_ptr<Core::Modules::Input::Delta> rotateInput = nullptr,
									   std::shared_ptr<Core::Modules::Input::Delta> zoomInput = nullptr)
		: camera(camera),
		move(camera->GetOrigin(), moveInput),
		rotate(camera->GetOrigin(), rotateInput),
		zoom(camera, zoomInput)
	{
		move.SetActive(false);
		rotate.SetActive(false);
		zoom.SetActive(false);
	};

	CameraController::~CameraController()
	{}

	void CameraController::Update()
	{
		rotate.Update();
		move.Update();
		zoom.Update();
	}

	IMoveController& CameraController::GetMoveController()
	{
		return move;
	}

	IRotateController& CameraController::GetRotateController()
	{
		return rotate;
	}

	IZoomController& CameraController::GetZoomController()
	{
		return zoom;
	}
}