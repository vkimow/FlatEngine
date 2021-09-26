#include "FlatEngine/Core/Objects/GameObject.h"
#include <stdexcept>
#include "..\..\..\..\include\FlatEngine\Core\Objects\ObjectComponent.h"

namespace Flat::Core::Objects
{
	ObjectComponent::ObjectComponent()
		: gameObject(nullptr),
		isActive(false)
	{}

	ObjectComponent::~ObjectComponent()
	{}

	void ObjectComponent::SetActive(bool value) { isActive = value; }

	bool ObjectComponent::IsActive() const
	{
		return isActive && gameObject->IsActive();
	}

	void ObjectComponent::SetGameObject(GameObject * gameObject)
	{
		if (this->gameObject != nullptr)
		{
			throw std::logic_error("Component can't be attached to 2 different gameobjects");
		}

		this->gameObject = gameObject;
		isActive = true;
	}
}