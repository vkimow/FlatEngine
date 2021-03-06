#include "FlatEngine/Core/Display/Elements/Shape.h"

namespace Flat::Core{

Shape::Shape()
	: Shape(std::shared_ptr<sf::Shape>())
{}

Shape::Shape(std::shared_ptr<sf::Shape> shape)
	: Shape(shape, 0)
{}

Shape::Shape(std::shared_ptr<sf::Shape> shape, size_t displayOrder)
	: 
	shape(shape),
	DisplayElement(displayOrder)
{}

void Shape::UpdateDrawable(const Camera* const camera)
{
	sf::Vector2f screenPosition = GetScreenPosition(camera);
	shape->setPosition(std::move(screenPosition));
}

const sf::Drawable& Shape::GetDrawable() const
{
	return *shape;
}

std::shared_ptr<sf::Shape> Shape::GetShape() const
{
	return shape;
}

void Shape::SetShape(std::shared_ptr<sf::Shape> value)
{
	shape = value;
}

}