#pragma once

#include "Core/FlatEngineApi.h"
#include "Display\Camera\Camera.h"
#include "Update\UpdateElement.h"
#include "Input\Elements\Vector\Vector.h"
#include "Controllers/Transform/IScaleController.h"
#include "Transform/IScalable.h"


namespace FlatEngine::Actors::Controllers
{
	class FLAT_ENGINE_API ScaleController final : public IScaleController, public Core::UpdateElement
	{
	public:
		ScaleController(std::shared_ptr<Core::IScalable> scalable,
					   std::shared_ptr<Input::Vector> input);

		ScaleController(std::shared_ptr < Core::IScalable> scalable,
					   std::shared_ptr<Input::Vector> input,
					   float speed);

		~ScaleController();

	public:
		virtual void Update() override;

		virtual float GetSpeed() const override { return speed; }
		virtual void SetSpeed(float value) override { speed = value; }

	protected:
		virtual void Scale(const sf::Vector2f& delta) override;

	private:
		std::shared_ptr<Core::IScalable> scalable;
		std::shared_ptr<Input::Vector> input;
		float speed;
	};
}