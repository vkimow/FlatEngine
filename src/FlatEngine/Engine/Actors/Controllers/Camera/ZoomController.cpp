#include "FlatEngine/Engine/Actors/Controllers/Camera/ZoomController.h"

namespace Flat::Engine::Actors
{
	ZoomController::ZoomController(Core::Camera* camera,
								   std::shared_ptr<Core::Input::Delta> input)
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