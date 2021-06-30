#include "FlatEngine/Core/Input/Elements/Delta/Delta.h"
#include "FlatEngine/Core/Input/Main/InputModule.h"

namespace Flat::Core::Input
{
	Delta::Delta()
		: Delta(0.05f)
	{}

	Delta::Delta(float threshold)
		:
		delta(0),
		threshold(threshold)
	{}

	Delta::~Delta()
	{}

	void Delta::UpdateInput(const sf::Event& event)
	{
		float deltaNow = GetDeltaInput(event);

		if (abs(deltaNow) < threshold)
		{
			deltaNow = 0;
		}

		if (deltaNow != delta)
		{
			ChangeDelta(deltaNow);
		}
	}

	void Delta::ChangeDelta(float value)
	{
		delta = value;
		OnDeltaChange(value);
	}
}