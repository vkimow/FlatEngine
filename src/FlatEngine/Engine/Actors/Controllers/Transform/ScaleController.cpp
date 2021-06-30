#include "FlatEngine/Engine/Actors/Controllers/Transform/ScaleController.h"
#include "FlatEngine/Core/Time/TimeModule.h"
#include "FlatEngine/Core/Main/Tools/Vector/VectorTools.h"

namespace Flat::Engine::Actors
{

	ScaleController::ScaleController(std::shared_ptr<Core::IScalable> scalable,
								   std::shared_ptr<Core::Input::Vector> input)
		: ScaleController(scalable, input, 1)
	{}

	ScaleController::ScaleController(std::shared_ptr<Core::IScalable> scalable,
								   std::shared_ptr<Core::Input::Vector> input,
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