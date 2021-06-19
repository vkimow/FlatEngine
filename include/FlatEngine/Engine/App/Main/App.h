#pragma once
#include "Main/FlatEngineApi.h"
#include <string>

#pragma region Forward Declaration

namespace FlatEngine
{
	class GameLooper;
}

#pragma endregion

namespace FlatEngine
{
	class FLAT_ENGINE_API App
	{
	public:
		App();
		App(const App& rhs) = delete;
		App(App&& rhs) = delete;
		App(std::string appName, unsigned int width, unsigned int height);
		~App();

	public:
		void Start();
		static void Quit();

	private:
		static bool isAppActive;
		sf::Window* sfmlApp;
		GameLooper* gameLooper;
	};
}
