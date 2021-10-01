#pragma once
#include "FlatEngine/Core/Transform/ITransformable.h"
#include "FlatEngine/Core/Update/UpdateElement.h"
#include <unordered_map>
#include <type_traits>

namespace Flat::Core::Objects
{
	class ObjectComponent;

	class FLAT_ENGINE_API GameObject : UpdateElement
	{
	public:
		GameObject();

		GameObject(const GameObject& object) = delete;
		GameObject(GameObject&& object) noexcept = delete;

		GameObject& operator=(const GameObject& object) = delete;
		GameObject& operator=(GameObject&& object) noexcept = delete;

		virtual ~GameObject();

	public:
		virtual void Update() override;

	public:
		void SetActive(bool value) { isActive = value; }
		bool IsActive() const { return isActive; }

	public:
		Flat::Core::ITransformable* const GetTransform() { return transform.get(); }

	public:
		template <typename Component,
			std::enable_if_t<std::is_base_of_v<ObjectComponent, Component>, int> = 0,
			std::enable_if_t<!std::is_abstract_v<Component>, int> = 0>
			void AddComponent(std::unique_ptr<Component>&& component)
		{
			std::type_info typeInfo = typeid(Component);
			size_t hashCode = typeInfo.hash_code();

			components.emplace(std::make_pair<size_t, std::unique_ptr<Component>>(hashCode, std::move(component)));
			components[hashCode]->SetGameObject(this);
		}

		template <typename Component, typename... _Types,
			std::enable_if_t<std::is_base_of_v<ObjectComponent, Component>, int> = 0,
			std::enable_if_t<!std::is_abstract_v<Component>, int> = 0>
			void CreateComponent(_Types&&... args)
		{
			Component* componentPtr = new Component(std::forward(args)...);
			std::unique_ptr<Component> component(componentPtr);
			AddComponent<Component>(std::move(component));
		}

		template <typename Component,
			std::enable_if_t<std::is_base_of_v<ObjectComponent, Component>, int> = 0,
			std::enable_if_t<!std::is_abstract_v<Component>, int> = 0>
			void ContainsComponent()
		{
			std::type_info typeInfo = typeid(Component);
			size_t hashCode = typeInfo.hash_code();

			return components.find(hashCode) != components.end();
		}

		template <typename Component,
			std::enable_if_t<std::is_base_of_v<ObjectComponent, Component>, int> = 0,
			std::enable_if_t<!std::is_abstract_v<Component>, int> = 0>
			void RemoveComponent()
		{
			std::type_info typeInfo = typeid(Component);
			size_t hashCode = typeInfo.hash_code();
			components.erase(hashCode);
		}

		template <typename Component,
			std::enable_if_t<std::is_base_of_v<ObjectComponent, Component>, int> = 0,
			std::enable_if_t<!std::is_abstract_v<Component>, int> = 0>
			Component* const GetComponent()
		{

			std::type_info typeInfo = typeid(Component);
			size_t hashCode = typeInfo.hash_code();
			auto component = components.find(hashCode);

			if (component == components.end())
				return nullptr;

			return component->second.get();
		}

	private:
		bool isActive;
		std::unique_ptr<Flat::Core::ITransformable> transform;
		std::unordered_map<size_t, std::unique_ptr<ObjectComponent>> components;
	};
}