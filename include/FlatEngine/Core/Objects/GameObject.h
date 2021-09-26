#pragma once
#include "FlatEngine/Core/Transform/ITransformable.h"
#include <unordered_map>
#include <type_traits>

namespace Flat::Core::Objects
{
	class ObjectComponent;

	class GameObject
	{
	public:
		GameObject();

		GameObject(const GameObject& object) = delete;
		GameObject(GameObject&& object) noexcept = delete;

		GameObject& operator=(const GameObject& object) = delete;
		GameObject& operator=(GameObject&& object) noexcept = delete;

		virtual ~GameObject();

	public:
		void SetActive(bool value) { isActive = value; }
		bool IsActive() const { return isActive; }

	public:
		Flat::Core::ITransformable* const GetTransform() { return transform.get(); }

	public:
		template <typename Component, typename... _Types,
			std::enable_if_t<std::is_base_of_v<ObjectComponent, Component>, int> = 0,
			std::enable_if_t<!std::is_abstract_v<Component>, int> = 0>
			void AddComponent(_Types&&... args)
		{
			std::unique_ptr<Component> component(CreateComponent(args));
			AddComponent<Component>(std::move(component);
		}

		template <typename Component,
			std::enable_if_t<std::is_base_of_v<ObjectComponent, Component>, int> = 0,
			std::enable_if_t<!std::is_abstract_v<Component>, int> = 0>
			void AddComponent(std::unique_ptr<Component>&& component)
		{
			std::type_info typeInfo = typeid(Component)
			components.insert(typeInfo, std::forward(component));
			components[typeInfo]->SetGameObject(this);
		}

		template <typename Component, typename... _Types,
			std::enable_if_t<std::is_base_of_v<ObjectComponent, Component>, int> = 0,
			std::enable_if_t<!std::is_abstract_v<Component>, int> = 0>
			Component* CreateComponent(_Types&&... args)
		{
			return new Component(std::forward<_Types>(args)..., *this);
		}

		template <typename Component,
			std::enable_if_t<std::is_base_of_v<ObjectComponent, Component>, int> = 0,
			std::enable_if_t<!std::is_abstract_v<Component>, int> = 0>
			void ContainsComponent()
		{
			std::type_info typeInfo = typeid(Component);
			return components.find(typeInfo) != components.end();
		}

		template <typename Component,
			std::enable_if_t<std::is_base_of_v<ObjectComponent, Component>, int> = 0,
			std::enable_if_t<!std::is_abstract_v<Component>, int> = 0>
			void RemoveComponent()
		{
			std::type_info typeInfo = typeid(Component);
			components.erase(typeInfo);
		}

		template <typename Component,
			std::enable_if_t<std::is_base_of_v<ObjectComponent, Component>, int> = 0,
			std::enable_if_t<!std::is_abstract_v<Component>, int> = 0>
			Component* const GetComponent()
		{
			std::type_info typeInfo = typeid(Component);
			auto component = components.find(typeInfo);

			if (component == components.end())
				return nullptr;

			return component->second.get();
		}

	private:
		bool isActive;
		const std::unique_ptr<Flat::Core::ITransformable> transform;
		const std::unordered_map<const std::type_info, const std::unique_ptr<ObjectComponent>> components;

	};
}