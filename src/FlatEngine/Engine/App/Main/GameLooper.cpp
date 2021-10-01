#include "FlatEngine/Engine/App/Main/GameLooper.h"
#include "FlatEngine/Core/Time/TimeModule.h"
#include "FlatEngine/Core/Update/UpdateModule.h"
#include "FlatEngine/Core/Display/Main/DisplayModule.h"
#include "FlatEngine/Core/Input/Main/InputModule.h"

namespace Flat::Engine
{
	GameLooper::GameLooper(App* app, sf::RenderWindow* renderWindow)
		:
		inputModule(new Core::InputModule(renderWindow)),
		timeModule(new Core::TimeModule()),
		logicModule(new Core::UpdateModule()),
		displayModule(new Core::DisplayModule(renderWindow))
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