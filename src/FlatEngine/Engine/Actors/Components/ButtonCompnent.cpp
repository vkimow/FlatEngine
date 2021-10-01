#include "FlatEngine\Engine\Actors\Components\ButtonCompnent.h"
#include "FlatEngine/Core/Objects/GameObject.h"
#include "FlatEngine/Core/Main/Events/MemberFunction.h"
#include "FlatEngine/Core/Input/Elements/Mouse.h"

namespace Flat::Engine::Actors
{
	ButtonComponent::ButtonComponent(float height, float width)
		: click(Core::Input::PressableMouse(sf::Mouse::Button::Left)),
		height(height),
		width(width),
		isOverlaped(false),
		isClicked(false)
	{
		//auto onPress1 = Core::MemberFunction<ButtonComponent, void>::Create(this, &ButtonComponent::Click);
		//Core::MemberFunction<ButtonComponent, void> onPress(this, &ButtonComponent::Click);
		//Core::MemberFunction<ButtonComponent, void> onRelease(this, &ButtonComponent::Release);
		//click.AddListenerOnPress(onPress);
		//click.AddListenerOnRelease(onRelease);
	};

	ButtonComponent::~ButtonComponent()
	{}

	void ButtonComponent::Update()
	{
		sf::Vector2f mousePos = (sf::Vector2f)Core::Input::Mouse::GetPosition();

		if (IsOverlaping(mousePos))
		{
			Overlap();
			return;
		}

		isClicked = false;
		isOverlaped = false;
	}

	bool ButtonComponent::IsOverlaping(sf::Vector2f position)
	{
		sf::Vector2f buttonPos = GetGameObject()->GetTransform()->GetPosition();

		if (position.x < buttonPos.x + width 
			&& position.x > buttonPos.x 
			&& position.y < buttonPos.y + height 
			&& position.y > buttonPos.y) 
		{
			return true;
		}

		return false;
	}

	void ButtonComponent::Overlap()
	{
		if (!isOverlaped)
		{
			isOverlaped = true;
			OnButtonOverlaped();
		}
	};

	void ButtonComponent::Click()
	{
		if (isOverlaped && !isClicked)
		{
			isClicked = true;
			OnButtonClicked();
		}
	}
	void ButtonComponent::Release()
	{
		isClicked = false;
	}
}