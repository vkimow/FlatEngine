#pragma once

#include <Core.h>
#include "Modules\Display\Camera\Camera.h"
#include "Modules\Update\UpdateElement.h"
#include "Modules\Input\InputHeader.h"
#include "IRotateController.h"


namespace FlatEngine::Actors::Controllers
{
	class FLAT_ENGINE_API RotateController final : public IRotateController, public Core::Modules::UpdateElement
	{
	public:
		RotateController(std::shared_ptr < Core::Simulation::IRotatable> rotatable,
						 std::shared_ptr<Core::Modules::Input::Delta> input);

		RotateController(std::shared_ptr < Core::Simulation::IRotatable> rotatable,
						 std::shared_ptr<Core::Modules::Input::Delta> input,
						 float speed);

		~RotateController();

	public:
		virtual void Update() override;

		virtual float GetSpeed() const override { return speed; }
		virtual void SetSpeed(float value) override { speed = value; }

	protected:
		virtual void Rotate(float delta) override;

	private:
		std::shared_ptr<Core::Simulation::IRotatable> rotatable;
		std::shared_ptr<Core::Modules::Input::Delta> input;
		float speed;
	};
}