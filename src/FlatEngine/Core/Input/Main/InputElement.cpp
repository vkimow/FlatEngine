#include "FlatEngine/Core/Input/Main/InputElement.h"
#include "FlatEngine/Core/Input/Main/InputModule.h"

namespace Flat::Core
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
