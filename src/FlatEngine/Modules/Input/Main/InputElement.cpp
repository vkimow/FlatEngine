#include "Main/InputElement.h"
#include "Main/InputModule.h"

namespace FlatEngine::Input
{
	InputElement::InputElement()
		:
		isActive(true)
	{
		InputModule::AddElement(this);
	}

	InputElement::~InputElement()
	{
		InputModule::RemoveElement(this);
	}

	void InputElement::SetActive(bool value)
	{
		isActive = value;
	}
}
