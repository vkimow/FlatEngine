#pragma once

#include "Main/FlatEngineApi.h"
#include "SFML/Window.hpp"

#pragma region Forward Declaration

namespace FlatEngine::Core::Modules
{
	class InputElement;
}

#pragma endregion

namespace FlatEngine::Input
{
	class FLAT_ENGINE_API InputModule final
	{
		friend class GameLooper;
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

	private:
		static void AddElement(InputElement* element);
		static void RemoveElement(InputElement* element);
	};
}