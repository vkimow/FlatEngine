#pragma once

#include "Core/FlatEngineApi.h"
#include "Display\Camera\Camera.h"
#include "Update\UpdateElement.h"
#include "Input/Main/InputModule.h"
#include "Controllers/Transform/IMoveController.h"
#include "Transform/ITransformable.h"
#include "Transform/IMovable.h"
#include "Input/Elements/Vector/Vector.h"


namespace FlatEngine::Actors::Controllers
{
	class FLAT_ENGINE_API MoveController final : public IMoveController, public Core::UpdateElement
	{
	public:
		MoveController(std::shared_ptr <Core::IMovable> movable,
					   std::shared_ptr<Input::Vector> input);

		MoveController(std::shared_ptr <Core::IMovable> movable,
					   std::shared_ptr<Input::Vector> input,
					   float speed);

		~MoveController();

	public:
		virtual void Update() override;

		virtual float GetSpeed() const override { return speed; }
		virtual void SetSpeed(float value) override { speed = value; }

	protected:
		virtual void Move(const sf::Vector2f& delta) override;

	private:
		std::shared_ptr<Core::IMovable> movable;
		std::shared_ptr<Input::Vector> input;
		float speed;
	};
}