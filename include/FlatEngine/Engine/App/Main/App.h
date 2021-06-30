#pragma once
#include "FlatEngine/Core/Main/FlatEngineApi.h"
#include "SFML/Graphics.hpp"
#include <string>

namespace Flat::Engine
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
		class GameLooper* gameLooper;
	};
}
