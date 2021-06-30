#pragma once

#include "FlatEngine/Core/Main/FlatEngineApi.h"
#include "FlatEngine/Core/Display/Camera/Camera.h"
#include "FlatEngine/Core/Update\UpdateElement.h"
#include "FlatEngine/Core/Input/Main/InputModule.h"
#include "FlatEngine/Engine/Actors/Controllers/Transform/IMoveController.h"
#include "FlatEngine/Core/Transform/ITransformable.h"
#include "FlatEngine/Core/Transform/IMovable.h"
#include "FlatEngine/Core/Input/Elements/Vector/Vector.h"


namespace Flat::Engine::Actors
{
	class FLAT_ENGINE_API MoveController final : public IMoveController, public Core::UpdateElement
	{
	public:
		MoveController(std::shared_ptr <Core::IMovable> movable,
					   std::shared_ptr<Core::Input::Vector> input);

		MoveController(std::shared_ptr <Core::IMovable> movable,
					   std::shared_ptr<Core::Input::Vector> input,
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
		std::shared_ptr<Core::Input::Vector> input;
		float speed;
	};
}