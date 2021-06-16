#include "Transformable.h"
#include <iostream>

namespace FlatEngine::Core::Simulation
{
	Transformable::Transformable()
		: Transformable(sf::Vector2f())
	{};

	Transformable::Transformable(sf::Vector2f position)
		: Transformable(position, 0)
	{};

	Transformable::Transformable(sf::Vector2f position, float rotation)
		: Transformable(position, rotation, sf::Vector2f())
	{};

	Transformable::Transformable(sf::Vector2f position, sf::Vector2f scale)
		: Transformable(position, 0, scale)
	{};

	Transformable::Transformable(sf::Vector2f position, float rotation, sf::Vector2f scale)
		: position(position), rotation(rotation), scale(scale)
	{};

	Transformable::Transformable(const Transformable& rhs)
		: Transformable(rhs.position,
						rhs.rotation,
						rhs.scale)
	{};

	Transformable::Transformable(Transformable&& rhs) noexcept
		: Transformable(std::move(rhs.position),
						std::move(rhs.rotation),
						std::move(rhs.scale))
	{};

	Transformable& Transformable::operator=(const Transformable& rhs)
	{
		position = rhs.position;
		rotation = rhs.rotation;
		scale = rhs.scale;
		return *this;
	}

	Transformable& Transformable::operator=(Transformable&& rhs) noexcept
	{
		position = std::move(rhs.position);
		rotation = std::move(rhs.rotation);
		scale = std::move(rhs.scale);
		return *this;
	}

	void Transformable::SetPosition(const sf::Vector2f& value)
	{
		position = value;
	}

	void Transformable::SetRotation(float value)
	{
		int quotient = (int)(value / MAX_ROTATION);
		value -= MAX_ROTATION * quotient;
		rotation = value;
	}

	void Transformable::SetScale(const sf::Vector2f& value)
	{
		scale = value;
	}

	void Transformable::Move(const sf::Vector2f& delta)
	{
		SetPosition(position + delta);
	}

	void Transformable::Rotate(float delta)
	{
		SetRotation(rotation + delta);
	}

	void Transformable::Scale(const sf::Vector2f& delta)
	{
		SetScale(scale + delta);
	}

	std::ostream& operator<<(std::ostream& out, const ITransformable& transformable)
	{
		out << "P:(" << transformable.GetPosition().x << ',' << transformable.GetPosition().y << ") "
			<< "R:" << transformable.GetRotation() << ' '
			<< "S:(" << transformable.GetScale().x << ',' << transformable.GetScale().y << ")";

		return out;
	}
}