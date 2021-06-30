#pragma once

#include "FlatEngine/Core/Main/FlatEngineApi.h"
#include "FlatEngine/Core/Display/Camera/Camera.h"
#include "FlatEngine/Core/Update\UpdateElement.h"
#include "FlatEngine/Core/Input/Elements/Delta/Delta.h"
#include "FlatEngine/Engine/Actors/Controllers/Transform/IRotateController.h"
#include "FlatEngine/Core/Transform/IRotatable.h"


namespace Flat::Engine::Actors
{
	class FLAT_ENGINE_API RotateController final : public IRotateController, public Core::UpdateElement
	{
	public:
		RotateController(std::shared_ptr<Core::IRotatable> rotatable,
						 std::shared_ptr<Core::Input::Delta> input);

		RotateController(std::shared_ptr<Core::IRotatable> rotatable,
						 std::shared_ptr<Core::Input::Delta> input,
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
		std::shared_ptr<Core::Input::Delta> input;
		float speed;
	};
}