#include "Elements/Delta/DeltaMouseWheel.h"

namespace FlatEngine::Input{

DeltaMouseWheel::DeltaMouseWheel(sf::Mouse::Wheel wheel)
	: wheel(wheel)
{}

DeltaMouseWheel::~DeltaMouseWheel()
{}

float DeltaMouseWheel::GetDeltaInput(const sf::Event& event)
{
	if(event.type == sf::Event::MouseWheelScrolled)
	{
		if(event.mouseWheelScroll.wheel == wheel)
		{
			return event.mouseWheelScroll.delta;
		}
	}

	return 0;
}

}
