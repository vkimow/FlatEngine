#include "FlatEngine/Core/Display/Main\DisplayModule.h"
#include "FlatEngine/Core/Display/Main\DisplayElement.h"
#include "FlatEngine/Core/Display/Camera\CameraManager.h"
#include "FlatEngine/Core/Display/Camera\Camera.h"
#include <iostream>

namespace Flat::Core
{
	std::vector<DisplayElement*> DisplayModule::elements = {};
	ScreenSettings* DisplayModule::screenSettings = nullptr;

	DisplayModule::DisplayModule(sf::RenderWindow* renderWindow)
		:
		renderWindow(renderWindow),
		cameraManager()
	{
		sf::Vector2u resolution = renderWindow->getSize();
		unsigned int width = resolution.x;
		unsigned int height = resolution.y;

		screenSettings = new ScreenSettings(width, height);
	}

	DisplayModule::~DisplayModule()
	{
		delete cameraManager;
		delete screenSettings;
	}

	void DisplayModule::Update()
	{
		renderWindow->clear();
		Camera* activeCamera = cameraManager->GetActiveCamera();

		if(activeCamera == nullptr)
			return;

		for(auto element : elements)
		{
			Update(element, activeCamera);
			Draw(element);
		}

		renderWindow->display();
	}

	inline void DisplayModule::Update(DisplayElement* element, const Camera* const camera)
	{
		element->UpdateDrawable(camera);
	}

	inline void DisplayModule::Draw(DisplayElement* element)
	{
		renderWindow->draw(element->GetDrawable());
	}

	void DisplayModule::AddElement(DisplayElement* element)
	{
		elements.push_back(element);
		SortElements();
	}

	void DisplayModule::RemoveElement(DisplayElement* element)
	{
		elements.erase(std::remove(elements.begin(), elements.end(), element));
	}

	void DisplayModule::SortElements()
	{
		std::sort(elements.begin(), elements.end(), [](DisplayElement* lhs, DisplayElement* rhs)
		{
			return lhs->GetDisplayOrder() < rhs->GetDisplayOrder();
		});
	}

}