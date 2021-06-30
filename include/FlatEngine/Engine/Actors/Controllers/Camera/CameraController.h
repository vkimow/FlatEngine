#pragma once

#include "FlatEngine/Core/Main/FlatEngineApi.h"
#include "FlatEngine/Core/Display\Camera\Camera.h"
#include "FlatEngine/Core/Update/UpdateElement.h"
#include "FlatEngine/Core/Input\Elements/Delta\Delta.h"
#include "FlatEngine/Core/Input/Elements/Vector/Vector.h"
#include "FlatEngine/Engine/Actors/Controllers/Transform/MoveController.h"
#include "FlatEngine/Engine/Actors/Controllers/Transform/RotateController.h"
#include "FlatEngine/Engine/Actors/Controllers/Camera/ICameraController.h"
#include "FlatEngine/Engine/Actors/Controllers/Camera/ZoomController.h"


namespace Flat::Engine::Actors
{
	class FLAT_ENGINE_API CameraController : public ICameraController, public Core::UpdateElement
	{
	public:
		CameraController(Core::Camera* camera,
						 std::shared_ptr<Core::Input::Vector> moveInput,
						 std::shared_ptr<Core::Input::Delta> rotateInput,
						 std::shared_ptr<Core::Input::Delta> zoomInput);



		~CameraController();

	public:
		virtual void Update() override;

	public:
		virtual IMoveController& GetMoveController() override;
		virtual IRotateController& GetRotateController() override;
		virtual IZoomController& GetZoomController() override;

	private:
		Core::Camera* camera;

		MoveController move;
		RotateController rotate;
		ZoomController zoom;
	};
}