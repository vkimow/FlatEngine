#pragma once

#include "FlatEngine/Core/Main/FlatEngineApi.h"
#include "FlatEngine/Core/Input\Elements/Delta\Delta.h"
#include "FlatEngine/Core/Display\Camera\Camera.h"
#include "FlatEngine/Core/Update\UpdateElement.h"
#include "FlatEngine/Engine/Actors/Controllers/Camera/IZoomController.h"

namespace Flat::Engine::Actors
{
	class FLAT_ENGINE_API ZoomController final : public IZoomController, public Core::UpdateElement
	{
	public:
		ZoomController(Core::Camera* camera,
					   std::shared_ptr<Core::Input::Delta> input);

		~ZoomController();

	public:
		virtual void Update() override;

		virtual float GetSpeed() const override final { return speed; } 
		virtual void SetSpeed(float value) override final { speed = value; }

	private:
		void Zoom(float delta);

	private:
		Core::Camera* camera;
		std::shared_ptr<Core::Input::Delta> input;

		float speed;
	};
}