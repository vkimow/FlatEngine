#pragma once

#include "FlatEngine/Core/Main/FlatEngineApi.h"
#include "FlatEngine/Core/Input/Elements/Mouse.h"
#include "SFML/Window.hpp"

#pragma region Forward Declaration

namespace Flat::Engine
{
	class GameLooper;
}

#pragma endregion

namespace Flat::Core
{
	namespace Input
	{
		class Mouse;
	}

	class FLAT_ENGINE_API InputModule final
	{
		friend class Engine::GameLooper;
		friend class InputElement;

	private:
		InputModule(sf::Window* sfmlWindow);
		InputModule() = delete;
		InputModule(const InputModule& inputModule) = delete;
		InputModule(InputModule&& inputModule) = delete;
		InputModule& operator=(const InputModule& rhs) = delete;
		InputModule& operator=(InputModule&& rhs) = delete;

	public:
		void Update();

	private:
		sf::Event mainEvent;
		sf::Window* sfmlWindow;

	private:
		static std::vector<InputElement*> elements;
		std::unique_ptr<Input::Mouse> mouse;

	private:
		static void AddElement(InputElement* element);
		static void RemoveElement(InputElement* element);
	};
}