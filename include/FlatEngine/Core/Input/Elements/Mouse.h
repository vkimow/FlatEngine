#pragma once

#include "FlatEngine/Core/Main/FlatEngineApi.h"
#include "SFML/Window.hpp"
#include "FlatEngine/Core/Input/Main/InputElement.h"
#include "FlatEngine/Core/Main/Events/Action.h"

namespace Flat::Core::Input
{
	class FLAT_ENGINE_API Mouse final : public InputElement
	{
	public:
		Mouse() = delete;
		Mouse(const sf::WindowBase& window);
		~Mouse();

	public:
		virtual void UpdateInput(const sf::Event& event) override final;
		static const sf::Vector2i GetPosition() { return position; }

	protected:
		sf::Vector2i GetPositionInput(const sf::Event& event);

	private:
		void ChangePosition(sf::Vector2i newPosition);

	private:
		const sf::WindowBase& window;
		static sf::Vector2i position;
	};

}

