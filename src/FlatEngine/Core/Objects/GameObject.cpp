#include "FlatEngine/Core/Objects/GameObject.h"
#include "FlatEngine/Core/Objects/ObjectComponent.h"
#include "FlatEngine/Core/Transform/Transformable.h"
#include "FlatEngine\Core\Objects\GameObjectModule.h"

namespace Flat::Core::Objects
{
	GameObject::GameObject()
		: isActive(true),
		transform(std::make_unique<ITransformable>(new Transformable())),
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