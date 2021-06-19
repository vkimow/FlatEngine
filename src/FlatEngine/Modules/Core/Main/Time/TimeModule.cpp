#include "Main/Time/TimeModule.h"

namespace FlatEngine::Core
{
	float TimeModule::deltaTime = 0;

	TimeModule::TimeModule()
		: clock()
	{}

	void TimeModule::Update()
	{
		deltaTime = clock.getElapsedTime().asSeconds();
		clock.restart();
	}
}