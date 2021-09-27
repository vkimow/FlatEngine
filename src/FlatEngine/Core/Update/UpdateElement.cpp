#include "FlatEngine/Core/Update/UpdateElement.h"
#include "FlatEngine/Core/Update/UpdateModule.h"

namespace Flat::Core
{
	UpdateElement::UpdateElement()
		: UpdateElement(true, 0)
	{}

	UpdateElement::UpdateElement(size_t updateOrder)
		: UpdateElement(true, updateOrder)
	{}

	UpdateElement::UpdateElement(bool isAutoUpdateEnabled)
		: UpdateElement(isAutoUpdateEnabled, 0)
	{}

	UpdateElement::UpdateElement(bool isAutoUpdateEnabled, size_t updateOrder)
		:isUpdateEnabled(isAutoUpdateEnabled),
		updateOrder(updateOrder)
	{
		UpdateModule::AddElement(this);
	}

	UpdateElement::~UpdateElement()
	{
		UpdateModule::RemoveElement(this);
	};

	void UpdateElement::SetUpdateOrder(size_t value)
	{
		updateOrder = value;
		UpdateModule::SortElements();
	};

	void UpdateElement::EnableUpdate(bool value)
	{
		isUpdateEnabled = value;
	};
}