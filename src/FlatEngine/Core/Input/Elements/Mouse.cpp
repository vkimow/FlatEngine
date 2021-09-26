#pragma once

#include "FlatEngine/Core/Main/FlatEngineApi.h"
#include "SFML/Window.hpp"
#include "FlatEngine/Core/Input/Main/InputElement.h"
#include "FlatEngine/Core/Main/Events/Action.h"
#include "..\..\..\..\..\include\FlatEngine\Core\Input\Elements\Mouse.h"

namespace Flat::Core::Input
{
	Mouse::Mouse(const sf::WindowBase& window)
		: window(window),
		position()
	{}

	Mouse::~Mouse()
	{}

	void Mouse::UpdateInput(const sf::Event& event)
	{
		sf::Vector2f newPosition = GetPositionInput(event);

		if (position != newPosition)
		{
			ChangePosition(newPosition);
		}
	}
	sf::Vector2f Mouse::GetPositionInput(const sf::Event& event)
	{
		sf::Mouse::getPosition(window);
	}

	void Mouse::ChangePosition(sf::Vector2f newPosition)
	{
			position = newPosition;
			OnPositionChange(newPosition);
	}
}

