#pragma once

#include "FlatEngine/Core/Main/FlatEngineApi.h"
#include "SFML/Graphics.hpp"
#include <memory>

namespace Flat::Core
{
	class Camera;
	class ITransformable;

	class FLAT_ENGINE_API DisplayElement
	{
	public:
		DisplayElement(std::shared_ptr<const ITransformable> origin);
		DisplayElement(std::shared_ptr<const ITransformable> origin, size_t displayOrder);

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

		std::shared_ptr<const ITransformable> GetOrigin() { return origin; }
		void SetOrigin(std::shared_ptr<const ITransformable> value);

	protected:
		sf::Vector2f GetScreenPosition(const Camera* const camera);

	private:
		std::shared_ptr<const ITransformable> origin;
		size_t displayOrder;

		friend std::ostream& operator<<(std::ostream& out, const DisplayElement& element);
	};
}