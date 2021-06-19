#include "Controllers/Camera/ZoomController.h"

namespace FlatEngine::Actors::Controllers
{
	ZoomController::ZoomController(Display::Camera* camera,
								   std::shared_ptr<Input::Delta> input)
		: camera(camera),
		input(input)
	{}

	ZoomController::~ZoomController()
	{}

	void ZoomController::Update()
	{

	}



	void ZoomController::Zoom(float delta)
	{

	}
}