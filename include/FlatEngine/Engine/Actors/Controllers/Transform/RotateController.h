#pragma once

#include "Core/Main/FlatEngineApi.h"
#include "Display/Camera/Camera.h"
#include "Core\Main\Update\UpdateElement.h"
#include "Input/Elements/Delta/Delta.h"
#include "Controllers/Transform/IRotateController.h"
#include "Core/Transform/IRotatable.h"


namespace FlatEngine::Actors::Controllers
{
	class FLAT_ENGINE_API RotateController final : public IRotateController, public Core::UpdateElement
	{
	public:
		RotateController(std::shared_ptr<Core::IRotatable> rotatable,
						 std::shared_ptr<Input::Delta> input);

		RotateController(std::shared_ptr<Core::IRotatable> rotatable,
						 std::shared_ptr<Input::Delta> input,
						 float speed);

		~RotateController();

	public:
		virtual void Update() override;

		virtual float GetSpeed() const override { return speed; }
		virtual void SetSpeed(float value) override { speed = value; }

	protected:
		virtual void Rotate(float delta) override;

	private:
		std::shared_ptr<Core::IRotatable> rotatable;
		std::shared_ptr<Input::Delta> input;
		float speed;
	};
}