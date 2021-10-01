#pragma once

#include "FlatEngine/Core/Main/FlatEngineApi.h"
#include "SFML/Window.hpp"
#include "FlatEngine/Core/Input/Main/InputElement.h"
#include "FlatEngine/Core/Main/Events/Action.h"
#include "FlatEngine\Core\Input\Elements\Mouse.h"

namespace Flat::Core::Input
{
	Mouse::Mouse(const sf::WindowBase& window)
		: window(window)
	{}

	Mouse::~Mouse()
	{}

	void Mouse::UpdateInput(const sf::Event& event)
	{
		sf::Vector2i newPosition = GetPositionInput(event);

		if (position != newPosition)
		{
			ChangePosition(newPosition);
		}
	}
	sf::Vector2i Mouse::GetPositionInput(const sf::Event& event)
	{
		return sf::Mouse::getPosition(window);
	}

	void Mouse::ChangePosition(sf::Vector2i newPosition)
	{
		position = newPosition;
	}

	sf::Vector2i Mouse::position = sf::Vector2i(0, 0);
}



