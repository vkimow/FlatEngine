#pragma once
#include "FlatEngine/Core/Transform/Transform.h"
#include "FlatEngine/Core/Display/Main/DisplayElement.h"

namespace Flat::Engine::Actors
{
	class GameObject
	{
	public:
		GameObject() = delete;
		GameObject(std::shared_ptr<Flat::Core::DisplayElement> display);
		GameObject(std::shared_ptr<Flat::Core::ITransformable> transform, std::shared_ptr<Flat::Core::DisplayElement> display);

		GameObject(const GameObject& object) = delete;
		GameObject(GameObject&& object) noexcept = delete;

		GameObject& operator=(const GameObject& object) = delete;
		GameObject& operator=(GameObject&& object) noexcept = delete;

		~GameObject();

	public:
		std::shared_ptr<Flat::Core::ITransformable> GetTransform() { return transform; }
		std::shared_ptr<Flat::Core::DisplayElement> GetDisplayElement() { return displayElement; }

	private:
		std::shared_ptr<Flat::Core::ITransformable> transform;
		std::shared_ptr<Flat::Core::DisplayElement> displayElement;
	};
}