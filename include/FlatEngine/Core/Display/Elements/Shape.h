#pragma once

#include "FlatEngine/Core/Main/FlatEngineApi.h"
#include "FlatEngine/Core/Display/Main/DisplayElement.h"
#include "FlatEngine/Core/Transform/ITransformable.h"
#include "SFML\Graphics.hpp"
#include <memory>

namespace Flat::Core
{
	class FLAT_ENGINE_API Shape : public DisplayElement
	{
	public:
		Shape();
		Shape(std::shared_ptr<sf::Shape> shape);
		Shape(std::shared_ptr<sf::Shape> shape, size_t displayOrder);

	public:
		virtual void UpdateDrawable(const Camera* const camera) override final;
		virtual const sf::Drawable& GetDrawable() const override final;

		std::shared_ptr<sf::Shape> GetShape() const;
		void SetShape(std::shared_ptr<sf::Shape> value);

	private:
		std::shared_ptr<sf::Shape> shape;
	};
}