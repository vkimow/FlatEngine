#include "InputElement.h"
#include "InputModule.h"

namespace FlatEngine::Core::Modules
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
