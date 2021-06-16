#include "ZoomController.h"

namespace FlatEngine::Actors::Controllers
{
	ZoomController::ZoomController(Core::Modules::Display::Camera* camera,
								   std::shared_ptr<Core::Modules::Input::Delta> input)
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