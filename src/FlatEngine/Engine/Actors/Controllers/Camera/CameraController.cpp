#include "FlatEngine/Engine/Actors/Controllers/Camera/CameraController.h"
#include <functional>

namespace Flat::Engine::Actors
{
	CameraController::CameraController(Core::Camera* camera,
		std::shared_ptr<Core::Input::Vector> moveInput = nullptr,
		std::shared_ptr<Core::Input::Delta> rotateInput = nullptr,
		std::shared_ptr<Core::Input::Delta> zoomInput = nullptr)
		: camera(camera),
		move(),
		rotate(),
		zoom()
	{
		if (moveInput.get() != nullptr)
		{
			move = std::make_shared<MoveController>(camera->GetOrigin(), moveInput);
		}

		if (rotateInput.get() != nullptr)
		{
			rotate = std::make_shared<RotateController>(camera->GetOrigin(), rotateInput);
		}

		if (zoomInput.get() != nullptr)
		{
			zoom = std::make_shared<ZoomController>(camera->GetOrigin(), zoomInput);
		}

		move->EnableUpdate(false);
		rotate->EnableUpdate(false);
		zoom->EnableUpdate(false);
	};

	CameraController::~CameraController()
	{}

	void CameraController::Update()
	{
		if (move.get() != nullptr)
		{
			move->Update();
		}

		if (rotate.get() != nullptr)
		{
			rotate->Update();
		}

		if (zoom.get() != nullptr)
		{
			zoom->Update();
		}
	}

	std::shared_ptr <IMoveController> CameraController::GetMoveController()
	{
		return move;
	}

	std::shared_ptr <IRotateController> CameraController::GetRotateController()
	{
		return rotate;
	}

	std::shared_ptr <IZoomController> CameraController::GetZoomController()
	{
		return zoom;
	}
}