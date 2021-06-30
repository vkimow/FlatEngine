#include "FlatEngine/Core/Input/Elements/Press/Pressable.h"
#include "FlatEngine/Core/Input/Main/InputModule.h"

namespace Flat::Core::Input
{

	Pressable::Pressable()
		:
		isPressed(false)
	{}

	Pressable::~Pressable()
	{}

	void Pressable::UpdateInput(const sf::Event& event)
	{
		bool isPressedInput = GetPressInput(event);

		if (isPressedInput && !isPressed)
		{
			Press();
			return;
		}

		if (!isPressedInput && isPressed)
		{
			Release();
			return;
		}
	}

	void Pressable::Press()
	{
		isPressed = true;
		OnPress();
	}

	void Pressable::Release()
	{
		isPressed = false;
		OnRelease();
	}
}