#pragma once

#include <Core.h>

#pragma region Forward Declaration
namespace FlatEngine::Core
{
	class App;
}

namespace FlatEngine::Core::Modules
{
	class InputModule;
	class TimeModule;
	class UpdateModule;
	class DisplayModule;
}

namespace sf
{
	class RenderWindow;
}
#pragma endregion

namespace FlatEngine::Core
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
		Modules::InputModule* inputModule;
		Modules::TimeModule* timeModule;
		Modules::UpdateModule* logicModule;
		Modules::DisplayModule* displayModule;
	};
}
