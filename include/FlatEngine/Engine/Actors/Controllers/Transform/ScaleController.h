#pragma once

#include <Core.h>
#include "Modules\Display\Camera\Camera.h"
#include "Modules\Update\UpdateElement.h"
#include "Modules\Input\InputHeader.h"
#include "IScaleController.h"


namespace FlatEngine::Actors::Controllers
{
	class FLAT_ENGINE_API ScaleController final : public IScaleController, public Core::Modules::UpdateElement
	{
	public:
		ScaleController(std::shared_ptr < Core::Simulation::IScalable> scalable,
					   std::shared_ptr<Core::Modules::Input::Vector> input);

		ScaleController(std::shared_ptr < Core::Simulation::IScalable> scalable,
					   std::shared_ptr<Core::Modules::Input::Vector> input,
					   float speed);

		~ScaleController();

	public:
		virtual void Update() override;

		virtual float GetSpeed() const override { return speed; }
		virtual void SetSpeed(float value) override { speed = value; }

	protected:
		virtual void Scale(const sf::Vector2f& delta) override;

	private:
		std::shared_ptr<Core::Simulation::IScalable> scalable;
		std::shared_ptr<Core::Modules::Input::Vector> input;
		float speed;
	};
}