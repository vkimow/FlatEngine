#include "Main/App.h"
#include <iostream>
#include "SFML\Graphics.hpp"
#include "Core/Tools/VectorTools.h"
#include "Main/GameLooper.h"

namespace FlatEngine
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

		//std::shared_ptr<Simulation::Transformable> cameraTransform(new Simulation::Transformable());
		//Modules::Display::Camera camera(cameraTransform);

		//std::shared_ptr<Modules::Input::VectorPressable> cameraMoveInput(
		//	new Modules::Input::VectorPressable(
		//		sf::Keyboard::W,
		//		sf::Keyboard::S,
		//		sf::Keyboard::A,
		//		sf::Keyboard::D));

		//std::shared_ptr<Modules::Input::DeltaPressable> cameraZoomInput(
		//	new Modules::Input::DeltaPressable(
		//		sf::Keyboard::E,
		//		sf::Keyboard::Q));

		////Actors::Controllers::CameraController cameraController(&camera, cameraMoveInput, cameraZoomInput);

		//std::shared_ptr<Simulation::Transformable> shapeTransform(new Simulation::Transformable());
		//std::shared_ptr<sf::Shape> rectangleShape(new sf::RectangleShape(sf::Vector2f(10, 10)));

		//rectangleShape->setFillColor(sf::Color::Green);
		//rectangleShape->setPosition(0, 0);
		//Modules::Display::Shape rectangle(shapeTransform, rectangleShape, 0);

		//std::shared_ptr<sf::Shape> rectangleShape2(new sf::RectangleShape(sf::Vector2f(10, 10)));
		//rectangleShape2->setFillColor(sf::Color::Red);
		//rectangleShape2->setPosition(0, 0);
		//Modules::Display::Shape rectangle2(cameraTransform, rectangleShape2, 0);

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