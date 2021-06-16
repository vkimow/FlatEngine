#include "Pressable.h"
#include "Modules\Input\InputModule.h"

namespace FlatEngine::Core::Modules::Input {

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