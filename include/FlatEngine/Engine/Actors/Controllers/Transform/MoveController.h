#pragma once

#include "FlatEngineApi.h"
#include "Modules\Display\Camera\Camera.h"
#include "Modules\Update\UpdateElement.h"
#include "Modules\Input\InputHeader.h"
#include "IMoveController.h"


namespace FlatEngine::Actors::Controllers
{
	class FLAT_ENGINE_API MoveController final : public IMoveController, public Core::Modules::UpdateElement
	{
	public:
		MoveController(std::shared_ptr < Core::Simulation::IMovable> movable,
					   std::shared_ptr<Core::Modules::Input::Vector> input);

		MoveController(std::shared_ptr < Core::Simulation::IMovable> movable,
					   std::shared_ptr<Core::Modules::Input::Vector> input,
					   float speed);

		~MoveController();

	public:
		virtual void Update() override;

		virtual float GetSpeed() const override { return speed; }
		virtual void SetSpeed(float value) override { speed = value; }

	protected:
		virtual void Move(const sf::Vector2f& delta) override;

	private:
		std::shared_ptr<Core::Simulation::IMovable> movable;
		std::shared_ptr<Core::Modules::Input::Vector> input;
		float speed;
	};
}