#pragma once

#include "FlatEngine/Core/Main/FlatEngineApi.h"
#include "SFML/Window.hpp"
#include "FlatEngine/Core/Input/Main/InputElement.h"
#include "FlatEngine/Core/Main/Events/Action.h"

namespace Flat::Core::Input
{
	class FLAT_ENGINE_API Mouse : public InputElement
	{
	protected:
		Mouse(const sf::WindowBase& window);

	public:
		virtual ~Mouse();

	public:
		virtual void UpdateInput(const sf::Event& event) override final;
		const sf::Vector2f GetPosition() const { return position; }

	protected:
		sf::Vector2f GetPositionInput(const sf::Event& event);

	private:
		void ChangePosition(sf::Vector2f newPosition);

	private:
		CreateAction(sf::Vector2f, OnPositionChange)

	private:
		const sf::WindowBase& window;
		sf::Vector2f position;
	};

}

