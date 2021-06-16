#pragma once

#include <Core.h>
#include <memory>
#include "Simulation\ITransformable.h"

#pragma region Forward Declaration
namespace sf
{
	class Drawable;
}

namespace FlatEngine::Core::Modules::Display
{
	class Camera;
}
#pragma endregion

namespace FlatEngine::Core::Modules
{
	class FLAT_ENGINE_API DisplayElement
	{
	public:
		DisplayElement(std::shared_ptr<const Simulation::ITransformable> origin);
		DisplayElement(std::shared_ptr<const Simulation::ITransformable> origin, size_t displayOrder);
		virtual ~DisplayElement();

	public:
		virtual void UpdateDrawable(const Display::Camera* const camera) = 0;
		virtual const sf::Drawable& GetDrawable() const = 0;

		size_t GetDisplayOrder() const { return displayOrder; }
		void SetDisplayOrder(int value);

		std::shared_ptr<const Simulation::ITransformable> GetOrigin() { return origin; }
		void SetOrigin(std::shared_ptr<const Simulation::ITransformable> value);

	protected:
		sf::Vector2f GetScreenPosition(const Display::Camera* const camera);

	private:
		std::shared_ptr<const Simulation::ITransformable> origin;
		size_t displayOrder;

		friend std::ostream& operator<<(std::ostream& out, const DisplayElement& element);
	};
}