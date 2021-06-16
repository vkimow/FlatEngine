#include "GameLooper.h"
#include "ModulesHeader.h"

namespace FlatEngine::Core{

GameLooper::GameLooper(App* app, sf::RenderWindow* renderWindow)
	:
	inputModule(new Modules::InputModule(app, renderWindow)),
	timeModule(new Modules::TimeModule()),
	logicModule(new Modules::UpdateModule()),
	displayModule(new Modules::DisplayModule(renderWindow))
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