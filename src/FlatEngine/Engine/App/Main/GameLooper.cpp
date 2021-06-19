#include "Main/GameLooper.h"
#include "Core/Main/Time/TimeModule.h"
#include "Core/Main/Update/UpdateModule.h"
#include "Display/Main/DisplayModule.h"
#include "Input/Main/InputModule.h"

namespace FlatEngine
{
	GameLooper::GameLooper(App* app, sf::RenderWindow* renderWindow)
		:
		inputModule(new Input::InputModule(renderWindow)),
		timeModule(new Core::TimeModule()),
		logicModule(new Core::UpdateModule()),
		displayModule(new Display::DisplayModule(renderWindow))
	{}

	GameLooper::~GameLooper()
	{
		delete displayModule;
		delete logicModule;
		delete timeModule;
		delete inputModule;
	}

	void GameLooper::Loop()
	{
		InputLoop();
		TimeLoop();
		UpdateLoop();
		DisplayLoop();
	}

	void GameLooper::InputLoop()
	{
		inputModule->Update();
	}

	void GameLooper::TimeLoop()
	{
		timeModule->Update();
	}

	void GameLooper::UpdateLoop()
	{
		logicModule->Update();
	}

	void GameLooper::DisplayLoop()
	{
		displayModule->Update();
	}
}