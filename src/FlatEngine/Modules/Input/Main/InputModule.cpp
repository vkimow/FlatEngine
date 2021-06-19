#include "Main/InputModule.h"
#include "Main/InputElement.h"
#include <vector>


namespace FlatEngine::Input
{
	std::vector<InputElement*> InputModule::elements = {};

	InputModule::InputModule(sf::Window* sfmlWindow)
		:
		sfmlWindow(sfmlWindow),
		mainEvent()
	{};

	void InputModule::Update()
	{
		while(sfmlWindow->pollEvent(mainEvent))
		{
			if(mainEvent.type == sf::Event::Closed)
			{
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