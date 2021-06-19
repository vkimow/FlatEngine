#include "Elements\Vector/VectorDelta.h"
#include "Elements\Delta\Delta.h"
#include <iostream>

namespace FlatEngine::Input
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