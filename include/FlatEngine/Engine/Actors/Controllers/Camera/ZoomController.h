#pragma once

#include <Core.h>
#include "Modules\Input\InputHeader.h"
#include "Modules\Display\Camera\Camera.h"
#include "Modules\Update\UpdateElement.h"
#include "IZoomController.h"

namespace FlatEngine::Actors::Controllers
{
	class FLAT_ENGINE_API ZoomController final : public IZoomController, public Core::Modules::UpdateElement
	{
	public:
		ZoomController(Core::Modules::Display::Camera* camera,
					   std::shared_ptr<Core::Modules::Input::Delta> input);

		~ZoomController();

	public:
		virtual void Update() override;

		virtual float GetSpeed() const override final { return speed; } 
		virtual void SetSpeed(float value) override final { speed = value; }

	private:
		void Zoom(float delta);

	private:
		Core::Modules::Display::Camera* camera;
		std::shared_ptr<Core::Modules::Input::Delta> input;

		float speed;
	};
}