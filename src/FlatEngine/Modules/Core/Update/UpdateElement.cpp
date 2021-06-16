#include "UpdateElement.h"
#include "UpdateModule.h"

namespace FlatEngine::Core::Modules{
UpdateElement::UpdateElement()
	: UpdateElement(0)
{};

UpdateElement::UpdateElement(int updateOrder)
	: updateOrder(updateOrder), isActive(true)
{
	UpdateModule::AddElement(this);
};

UpdateElement::~UpdateElement()
{
	UpdateModule::RemoveElement(this);
};

void UpdateElement::SetUpdateOrder(int value)
{
	updateOrder = value;
	UpdateModule::SortElements();
};

void UpdateElement::SetActive(bool value)
{
	isActive = value;
};

}