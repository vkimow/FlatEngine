#include "Elements/Press/Pressable.h"
#include "Main\InputModule.h"

namespace FlatEngine::Input
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