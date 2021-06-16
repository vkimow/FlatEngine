#include "InputModule.h"
#include "InputElement.h"
#include "App.h"
#include <vector>


namespace FlatEngine::Core::Modules
{
	std::vector<InputElement*> InputModule::elements = {};

	InputModule::InputModule(App* app, sf::Window* sfmlWindow)
		:
		app(app),
		sfmlWindow(sfmlWindow),
		mainEvent()
	{};

	void InputModule::Update()
	{
		while(sfmlWindow->pollEvent(mainEvent))
		{
			if(mainEvent.type == sf::Event::Closed)
			{
				app->Quit();
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