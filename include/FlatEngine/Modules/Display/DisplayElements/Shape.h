#pragma once

#include <Core.h>
#include "Modules\Display\DisplayElement.h"
#include "SFML\Graphics.hpp"
#include <memory>

namespace FlatEngine::Core::Modules::Display
{
	class FLAT_ENGINE_API Shape : public DisplayElement
	{
	public:
		Shape() = delete;
		Shape(std::shared_ptr<const Simulation::ITransformable> origin);
		Shape(std::shared_ptr<const Simulation::ITransformable> origin, std::shared_ptr<sf::Shape> shape);
		Shape(std::shared_ptr<const Simulation::ITransformable> origin, std::shared_ptr<sf::Shape> shape, size_t displayOrder);

	public:
		virtual void UpdateDrawable(const Display::Camera* const camera) override final;
		virtual const sf::Drawable& GetDrawable() const override final;

		std::shared_ptr<sf::Shape> GetShape() const;
		void SetShape(std::shared_ptr<sf::Shape> value);

	private:
		std::shared_ptr<sf::Shape> shape;
	};
}