#pragma once

#include "FlatEngine/Core/Main/FlatEngineApi.h"
#include "FlatEngine/Core/Objects/GameObject.h"
#include "FlatEngine/Core/Objects/ObjectComponent.h"
#include "SFML/Graphics.hpp"
#include <memory>

namespace Flat::Core
{
	class Camera;

	class FLAT_ENGINE_API DisplayElement : public Objects::ObjectComponent
	{
	public:
		DisplayElement();
		DisplayElement(size_t displayOrder);

		DisplayElement(const DisplayElement& displayElement) = default;
		DisplayElement(DisplayElement&& displayElement) noexcept = default;

		DisplayElement& operator=(const DisplayElement& displayElement) = default;
		DisplayElement& operator=(DisplayElement&& displayElement) noexcept = default;

		virtual ~DisplayElement();

	public:
		virtual void UpdateDrawable(const Camera* const camera) = 0;
		virtual const sf::Drawable& GetDrawable() const = 0;

		size_t GetDisplayOrder() const { return displayOrder; }
		void SetDisplayOrder(int value);

	protected:
		sf::Vector2f GetScreenPosition(const Camera* const camera);

	private:
		size_t displayOrder;
		friend std::ostream& operator<<(std::ostream& out, const DisplayElement& element);
	};
}