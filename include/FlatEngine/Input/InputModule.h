#pragma once

#include <Core.h>
#include "SFML\Window.hpp"

#pragma region Forward Declaration

namespace FlatEngine::Core
{
	class App;
}

namespace FlatEngine::Core::Modules
{
	class InputElement;
}

#pragma endregion

namespace FlatEngine::Core::Modules
{
	class FLAT_ENGINE_API InputModule final
	{
		friend class GameLooper;
		friend class InputElement;

	private:
		InputModule(App* app, sf::Window* sfmlWindow);
		InputModule() = delete;
		InputModule(const InputModule& inputModule) = delete;
		InputModule(InputModule&& inputModule) = delete;

	public:
		void Update();

	private:
		App* app;
		sf::Event mainEvent;
		sf::Window* sfmlWindow;

	private:
		static std::vector<InputElement*> elements;

	private:
		static void AddElement(InputElement* element);
		static void RemoveElement(InputElement* element);
	};
}