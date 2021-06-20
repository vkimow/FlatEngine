#pragma once

#include "Core/FlatEngineApi.h"
#include "Input\Elements/Delta\Delta.h"
#include "Display\Camera\Camera.h"
#include "Update\UpdateElement.h"
#include "IZoomController.h"

namespace FlatEngine::Actors::Controllers
{
	class FLAT_ENGINE_API ZoomController final : public IZoomController, public Core::UpdateElement
	{
	public:
		ZoomController(Display::Camera* camera,
					   std::shared_ptr<Input::Delta> input);

		~ZoomController();

	public:
		virtual void Update() override;

		virtual float GetSpeed() const override final { return speed; } 
		virtual void SetSpeed(float value) override final { speed = value; }

	private:
		void Zoom(float delta);

	private:
		Display::Camera* camera;
		std::shared_ptr<Input::Delta> input;

		float speed;
	};
}