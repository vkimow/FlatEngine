#pragma once

#include "Main/FlatEngineApi.h"
#include "Transform/ITransformable.h"
#include "SFML/System.hpp"

namespace FlatEngine::Core
{
	class FLAT_ENGINE_API Transformable : public ITransformable
	{
	public:
		Transformable();
		Transformable(sf::Vector2f position);
		Transformable(sf::Vector2f position, float rotation);
		Transformable(sf::Vector2f position, sf::Vector2f scale);
		Transformable(sf::Vector2f position, float rotation, sf::Vector2f scale);
		Transformable(const Transformable& rhs);
		Transformable(Transformable&& rhs) noexcept;

		~Transformable() {};

		Transformable& operator=(const Transformable& rhs);
		Transformable& operator=(Transformable&& rhs) noexcept;

	public:
		virtual void Move(const sf::Vector2f& delta) override;
		virtual void Rotate(float delta) override;
		virtual void Scale(const sf::Vector2f& delta) override;

	public:
		virtual void SetPosition(const sf::Vector2f& value) override;
		virtual void SetRotation(float value) override;
		virtual void SetScale(const sf::Vector2f& value) override;

	public:
		virtual sf::Vector2f GetPosition() const override final { return position; }
		virtual float GetRotation() const override final { return rotation; }
		virtual sf::Vector2f GetScale() const override final { return scale; }

	private:
		sf::Vector2f position;
		float rotation;
		sf::Vector2f scale;

	private:
		const static int MAX_ROTATION = 360;
	};
}