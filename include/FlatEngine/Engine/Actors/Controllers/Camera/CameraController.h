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
		virtual std::shared_ptr<IMoveController> GetMoveController() override;
		virtual std::shared_ptr<IRotateController> GetRotateController() override;
		virtual std::shared_ptr<IZoomController> GetZoomController() override;

	private:
		Core::Camera* camera;

		std::shared_ptr<MoveController> move;
		std::shared_ptr<RotateController> rotate;
		std::shared_ptr<ZoomController> zoom;
	};
}