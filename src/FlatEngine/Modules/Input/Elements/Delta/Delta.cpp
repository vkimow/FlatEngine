#include "Delta.h"
#include "Modules\Input\InputModule.h"

namespace FlatEngine::Core::Modules::Input{

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

	if(deltaNow != delta)
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