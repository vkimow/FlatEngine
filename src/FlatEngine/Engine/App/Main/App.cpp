#include "FlatEngine/Engine/App/Main/App.h"
#include <iostream>
#include "FlatEngine/Core/Main/Tools/Vector/VectorTools.h"
#include "FlatEngine/Engine/App/Main/GameLooper.h"

namespace Flat::Engine
{
	bool App::isAppActive = false;

	App::App()
		: App("Flat Engine", 1280, 720)
	{}

	App::App(std::string appName, unsigned int width, unsigned int height)
	{
		sf::RenderWindow* renderWindow = new sf::RenderWindow(sf::VideoMode(width, height), appName);
		sfmlApp = renderWindow;
		gameLooper = new GameLooper(this, renderWindow);
	}

	App::~App()
	{
		delete gameLooper;
		delete sfmlApp;
	}

	void App::Start()
	{
		isAppActive = true;

		while (isAppActive)
		{
			gameLooper->Loop();
		}

		sfmlApp->close();
	}

	void App::Quit()
	{
		isAppActive = false;
	}
}