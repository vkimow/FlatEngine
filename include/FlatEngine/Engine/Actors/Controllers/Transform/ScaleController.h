#pragma once

#include "FlatEngine/Core/Main/FlatEngineApi.h"
#include "FlatEngine/Core/Display\Camera\Camera.h"
#include "FlatEngine/Core/Update\UpdateElement.h"
#include "FlatEngine/Core/Input\Elements\Vector\Vector.h"
#include "FlatEngine/Engine/Actors/Controllers/Transform/IScaleController.h"
#include "FlatEngine/Core/Transform/IScalable.h"


namespace Flat::Engine::Actors
{
	class FLAT_ENGINE_API ScaleController final : public IScaleController, public Core::UpdateElement
	{
	public:
		ScaleController(std::shared_ptr<Core::IScalable> scalable,
					   std::shared_ptr<Core::Input::Vector> input);

		ScaleController(std::shared_ptr <Core::IScalable> scalable,
					   std::shared_ptr<Core::Input::Vector> input,
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
		std::shared_ptr<Core::Input::Vector> input;
		float speed;
	};
}