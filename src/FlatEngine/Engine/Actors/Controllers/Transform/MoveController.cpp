#include "MoveController.h"
#include "Tools/ToolsHeader.h"
#include "Modules/Time/TimeHeader.h"

namespace FlatEngine::Actors::Controllers
{

	MoveController::MoveController(std::shared_ptr < Core::Simulation::IMovable> movable,
								   std::shared_ptr<Core::Modules::Input::Vector> input)
		: MoveController(movable, input, 1)
	{}

	MoveController::MoveController(std::shared_ptr<Core::Simulation::IMovable> movable,
								   std::shared_ptr<Core::Modules::Input::Vector> input,
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
		moveDelta *= speed * Core::Modules::TimeModule::GetDeltaTime();

		if (Core::Tools::Vector::IsZero(moveDelta))
		{
			Move(moveDelta);
		}
	}

	void MoveController::Move(const sf::Vector2f& delta)
	{
		movable->Move(delta);
	}
}