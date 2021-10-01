#include "FlatEngine/Engine/App/Main/App.h"
#include "FlatEngine/Core/Display/Elements/Shape.h"
#include "FlatEngine/Engine/Actors/Components/ButtonCompnent.h"
#include "FlatEngine/Core/Objects/GameObject.h"
#include "FlatEngine/Core/Main/Events/GlobalFunction.h"
#include <iostream>

void Overlap()
{
	std::cout << "Overlaped!\n";
}

void Click()
{
	std::cout << "Clicked!\n";
}

int main()
{
	Flat::Engine::App app("Sandbox", 480, 480);

	sf::Vector2f size(100, 100);
	std::shared_ptr<sf::RectangleShape> shape(new sf::RectangleShape(size));
	std::unique_ptr<Flat::Core::Shape> MyShape(new Flat::Core::Shape(shape));

	std::unique_ptr<Flat::Engine::Actors::ButtonComponent> button(new Flat::Engine::Actors::ButtonComponent(size.x, size.y));
	Flat::Core::GlobalFunction<void> onOverlap(&Overlap);
	Flat::Core::GlobalFunction<void> onClick(&Click);
	button->AddListenerOnButtonOverlaped(onOverlap);
	button->AddListenerOnButtonClicked(onClick);

	Flat::Core::Objects::GameObject* gameObject = new Flat::Core::Objects::GameObject();
	gameObject->AddComponent(std::move(MyShape));
	gameObject->AddComponent(std::move(button));

	app.Start();
	return 0;
}