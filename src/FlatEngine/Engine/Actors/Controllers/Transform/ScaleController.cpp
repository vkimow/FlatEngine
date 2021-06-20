#include "Controllers/Transform/ScaleController.h"
#include "Time/TimeModule.h"
#include "Tools/Vector/VectorTools.h"

namespace FlatEngine::Actors::Controllers
{

	ScaleController::ScaleController(std::shared_ptr<Core::IScalable> scalable,
								   std::shared_ptr<Input::Vector> input)
		: ScaleController(scalable, input, 1)
	{}

	ScaleController::ScaleController(std::shared_ptr<Core::IScalable> scalable,
								   std::shared_ptr<Input::Vector> input,
								   float speed)
		: scalable(scalable),
		input(input),
		speed(speed)
	{}

	ScaleController::~ScaleController()
	{}

	void ScaleController::Update()
	{
		sf::Vector2f scaleDelta = input->GetVector();
		scaleDelta = Core::Tools::Vector::Normalize(scaleDelta);
		scaleDelta *= speed * Core::TimeModule::GetDeltaTime();

		if (!Core::Tools::Vector::IsZero(scaleDelta))
		{
			Scale(scaleDelta);
		}
	}

	void ScaleController::Scale(const sf::Vector2f& delta)
	{
		scalable->Scale(delta);
	}
}