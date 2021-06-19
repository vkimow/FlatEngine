#pragma once

#include "Main/FlatEngineApi.h"
#include <memory>
#include "Transform\ITransformable.h"

#pragma region Forward Declaration
namespace sf
{
	class Drawable;
}

namespace FlatEngine::Display
{
	class Camera;
}
#pragma endregion

namespace FlatEngine::Display
{
	class FLAT_ENGINE_API DisplayElement
	{
	public:
		DisplayElement(std::shared_ptr<const Core::ITransformable> origin);
		DisplayElement(std::shared_ptr<const Core::ITransformable> origin, size_t displayOrder);
		virtual ~DisplayElement();

	public:
		virtual void UpdateDrawable(const Display::Camera* const camera) = 0;
		virtual const sf::Drawable& GetDrawable() const = 0;

		size_t GetDisplayOrder() const { return displayOrder; }
		void SetDisplayOrder(int value);

		std::shared_ptr<const Core::ITransformable> GetOrigin() { return origin; }
		void SetOrigin(std::shared_ptr<const Core::ITransformable> value);

	protected:
		sf::Vector2f GetScreenPosition(const Display::Camera* const camera);

	private:
		std::shared_ptr<const Core::ITransformable> origin;
		size_t displayOrder;

		friend std::ostream& operator<<(std::ostream& out, const DisplayElement& element);
	};
}