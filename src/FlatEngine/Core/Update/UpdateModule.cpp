#include "FlatEngine/Core/Update/UpdateModule.h"
#include "FlatEngine/Core/Update/UpdateElement.h"
#include <algorithm>

namespace Flat::Core
{
	std::vector<UpdateElement*> UpdateModule::elements = {};

	UpdateModule::UpdateModule() {}

	void UpdateModule::Update()
	{
		for (auto element : elements)
		{
			element->Update();
		}
	}

	void UpdateModule::AddElement(UpdateElement* element)
	{
		elements.push_back(element);
		SortElements();
	}

	void UpdateModule::RemoveElement(UpdateElement* element)
	{
		elements.erase(std::remove(elements.begin(), elements.end(), element));
	}

	void UpdateModule::SortElements()
	{
		std::sort(elements.begin(), elements.end(), [](UpdateElement* lhs, UpdateElement* rhs)
			{
				return lhs->GetUpdateOrder() < rhs->GetUpdateOrder();
			});
	}
}