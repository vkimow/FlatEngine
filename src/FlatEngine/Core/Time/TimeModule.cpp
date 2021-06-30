#include "FlatEngine/Core/Time/TimeModule.h"

namespace Flat::Core
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