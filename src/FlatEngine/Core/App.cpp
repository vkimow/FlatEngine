#include "App.h"
#include <iostream>

namespace FlatEngine::Core
{
	bool App::isAppActive = false;

	App::App()
		: App("Flat Engine", 1280, 720)
	{}

	App::App(std::string appName, unsigned int width, unsigned int height)
	{
	}

	App::~App()
	{
	}

	void App::Run()
	{
		while (true)
		{
			std::cout << "I'm running!";
		}
	}

	void App::Quit()
	{
		isAppActive = false;
	}
}