#include "VectorDelta.h"
#include "Modules\Input\InputElements\Delta\Delta.h"
#include <iostream>

namespace FlatEngine::Core::Modules::Input
{
	VectorDelta::VectorDelta(const std::shared_ptr<Delta>&x, const std::shared_ptr<Delta>&y)
		: x(x), y(y)
	{}

	sf::Vector2f VectorDelta::GetVectorInput(const sf::Event& event)
	{
		std::cout << "Get Vector Input" << std::endl;
		return sf::Vector2f(x->GetDelta(), y->GetDelta());
	}
}