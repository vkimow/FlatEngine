#include "FlatEngine/Core/Objects/GameObject.h"
#include "FlatEngine/Core/Objects/ObjectComponent.h"
#include "FlatEngine/Core/Transform/Transformable.h"

namespace Flat::Core::Objects
{
	GameObject::GameObject()
		: isActive(true),
		transform(std::unique_ptr<ITransformable>(new Transformable())),
		components()
	{}

	GameObject::~GameObject() = default;

	void GameObject::Update()
	{
		if (!isActive)
		{
			return;
		}

		for (auto it = components.begin(); it != components.end(); ++it)
		{
			if (!it->second->isActive)
				continue;

			it->second->Update();
		}
	}
}