#include "Controllers/Transform/RotateController.h"
#include "Core/Main/Time/TimeModule.h"

namespace FlatEngine::Actors::Controllers
{

	RotateController::RotateController(std::shared_ptr<Core::IRotatable> rotatable,
									   std::shared_ptr<Input::Delta> input)
		: RotateController(rotatable, input, 1)
	{}

	RotateController::RotateController(std::shared_ptr<Core::IRotatable> rotatable,
									   std::shared_ptr<Input::Delta> input,
									   float speed)
		: rotatable(rotatable),
		input(input),
		speed(speed)
	{}

	RotateController::~RotateController()
	{}

	void RotateController::Update()
	{
		float rotateDelta = input->GetDelta();
		rotateDelta *= speed * Core::TimeModule::GetDeltaTime();

		if (rotateDelta != 0)
		{
			Rotate(rotateDelta);
		}
	}

	void RotateController::Rotate(float delta)
	{
		rotatable->Rotate(delta);
	}
}