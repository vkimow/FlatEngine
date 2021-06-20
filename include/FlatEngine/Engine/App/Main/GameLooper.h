#pragma once

#include "Core/Main/FlatEngineApi.h"

#pragma region Forward Declaration
namespace FlatEngine
{
	class App;
}

namespace FlatEngine::Core
{
	class TimeModule;
	class UpdateModule;
}

namespace FlatEngine::Display
{
	class DisplayModule;
}

namespace FlatEngine::Input
{
	class InputModule;
}

namespace sf
{
	class RenderWindow;
}
#pragma endregion

namespace FlatEngine
{
	class FLAT_ENGINE_API GameLooper
	{
	public:
		GameLooper() = delete;
		GameLooper(GameLooper&& gameLooper) = delete;
		GameLooper(const GameLooper& gameLooper) = delete;
		GameLooper(App* app, sf::RenderWindow* renderWindow);
		~GameLooper();

	public:
		void Loop();

	private:
		void InputLoop();
		void TimeLoop();
		void UpdateLoop();
		void DisplayLoop();

	private:
		Input::InputModule* inputModule;
		Core::TimeModule* timeModule;
		Core::UpdateModule* logicModule;
		Display::DisplayModule* displayModule;
	};
}
