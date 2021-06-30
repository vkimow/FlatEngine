#pragma once

#include "FlatEngine/Core/Main/FlatEngineApi.h"
#include "SFML/Graphics.hpp"

#pragma region Forward Declaration
namespace Flat::Core
{
	class TimeModule;
	class UpdateModule;
	class DisplayModule;
	class InputModule;
	class RenderWindow;
}
#pragma endregion

namespace Flat::Engine
{
	class App;

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
		Core::InputModule* inputModule;
		Core::TimeModule* timeModule;
		Core::UpdateModule* logicModule;
		Core::DisplayModule* displayModule;
	};
}
