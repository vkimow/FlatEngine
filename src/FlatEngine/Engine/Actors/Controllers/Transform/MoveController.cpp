#include "FlatEngine/Engine/Actors/Controllers/Transform/MoveController.h"
#include "FlatEngine/Core/Time/TimeModule.h"
#include "FlatEngine/Core/Main/Tools/Vector/VectorTools.h"

namespace Flat::Engine::Actors
{

	MoveController::MoveController(std::shared_ptr<Core::IMovable> movable,
								   std::shared_ptr<Core::Input::Vector> input)
		: MoveController(movable, input, 1)
	{}

	MoveController::MoveController(std::shared_ptr<Core::IMovable> movable,
								   std::shared_ptr<Core::Input::Vector> input,
								   float speed)
		: movable(movable),
		input(input),
		speed(speed)
	{}

	MoveController::~MoveController()
	{}

	void MoveController::Update()
	{
		sf::Vector2f moveDelta = input->GetVector();
		moveDelta = Core::Tools::Vector::Normalize(moveDelta);
		moveDelta *= speed * Core::TimeModule::GetDeltaTime();

		if (!Core::Tools::Vector::IsZero(moveDelta))
		{
			Move(moveDelta);
		}
	}

	void MoveController::Move(const sf::Vector2f& delta)
	{
		movable->Move(delta);
	}
}