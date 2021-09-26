#include "FlatEngine/Core/Objects/GameObject.h"
#include "FlatEngine/Core/Transform/Transformable.h"

namespace Flat::Core::Objects
{
	GameObject::GameObject()
		: isActive(true),
		transform(std::make_unique<ITransformable>(new Transformable())),
		components()
	{}

	GameObject::~GameObject()
	{}
}