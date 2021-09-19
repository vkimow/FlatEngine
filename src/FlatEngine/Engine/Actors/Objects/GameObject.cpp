#include "FlatEngine/Engine/Actors/Objects/GameObject.h"

namespace Flat::Engine::Actors
{
	GameObject::GameObject(std::shared_ptr<Flat::Core::DisplayElement> display)
		: GameObject(std::make_shared<Flat::Core::ITransformable>(new Flat::Core::Transformable()), display)
	{}

	GameObject::GameObject(	std::shared_ptr<Flat::Core::ITransformable> transform,
							std::shared_ptr<Flat::Core::DisplayElement> display)
		: transform(transform),
		displayElement(display)
	{
		displayElement->SetOrigin(transform);
	}

	GameObject::~GameObject()
	{}
}