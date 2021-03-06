#include "FlatEngine/Core/Input/Main/InputModule.h"
#include "FlatEngine/Core/Input/Main/InputElement.h"
#include "FlatEngine/Engine/App/Main/App.h"
#include <vector>


namespace Flat::Core
{
	std::vector<InputElement*> InputModule::elements = {};

	InputModule::InputModule(sf::Window* sfmlWindow)
		:
		sfmlWindow(sfmlWindow),
		mainEvent(),
		mouse()
	{
		Input::Mouse* mouseee = new Input::Mouse(*sfmlWindow);
		mouse = std::unique_ptr<Input::Mouse>(mouseee);
	};

	void InputModule::Update()
	{
		while(sfmlWindow->pollEvent(mainEvent))
		{
			if(mainEvent.type == sf::Event::Closed)
			{
				Flat::Engine::App::Quit();
				return;
			}
		}

		for(auto element : elements)
		{
			if(element->IsActive())
			{
				element->UpdateInput(mainEvent);
			}
		}
	};

	void InputModule::AddElement(InputElement* element)
	{
		elements.push_back(element);
	}

	void InputModule::RemoveElement(InputElement* element)
	{
		elements.erase(std::remove(elements.begin(), elements.end(), element));
	}
}