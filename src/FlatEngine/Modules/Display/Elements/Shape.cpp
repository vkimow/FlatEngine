#include "Shape.h"

namespace FlatEngine::Core::Modules::Display{

Shape::Shape(std::shared_ptr<const Simulation::ITransformable> origin)
	: Shape(origin, std::shared_ptr<sf::Shape>())
{}

Shape::Shape(std::shared_ptr<const Simulation::ITransformable> origin, std::shared_ptr<sf::Shape> shape)
	: Shape(origin, shape, 0)
{}

Shape::Shape(std::shared_ptr<const Simulation::ITransformable> origin, std::shared_ptr<sf::Shape> shape, size_t displayOrder)
	: 
	shape(shape),
	DisplayElement(origin, displayOrder)
{}

void Shape::UpdateDrawable(const Display::Camera* const camera)
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