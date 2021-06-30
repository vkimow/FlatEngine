#include "FlatEngine/Core/Update/UpdateElement.h"
#include "FlatEngine/Core/Update/UpdateModule.h"

namespace Flat::Core
{
	UpdateElement::UpdateElement()
		: UpdateElement(0)
	{};

	UpdateElement::UpdateElement(size_t updateOrder)
		: updateOrder(updateOrder), isActive(true)
	{
		UpdateModule::AddElement(this);
	};

	UpdateElement::~UpdateElement()
	{
		UpdateModule::RemoveElement(this);
	};

	void UpdateElement::SetUpdateOrder(size_t value)
	{
		updateOrder = value;
		UpdateModule::SortElements();
	};

	void UpdateElement::SetActive(bool value)
	{
		isActive = value;
	};
}