#include "Main/Update/UpdateElement.h"
#include "Main/Update/UpdateModule.h"

namespace FlatEngine::Core
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