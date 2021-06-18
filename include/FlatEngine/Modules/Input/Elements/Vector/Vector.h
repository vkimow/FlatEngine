#pragma once

#include "FlatEngineApi.h"
#include "SFML/Window.hpp"
#include "Modules\Input\InputElement.h"
#include "Tools\Events\Action.h"

namespace FlatEngine::Core::Modules::Input
{

	class FLAT_ENGINE_API Vector : public InputElement
	{
	protected:
		Vector();
		Vector(float threshold);

	public:
		virtual ~Vector();

	public:
		virtual void UpdateInput(const sf::Event& event) override final;
		const sf::Vector2f GetVector() const { return vector; }

	protected:
		virtual sf::Vector2f GetVectorInput(const sf::Event& event) = 0;

	private:
		void ChangeVector(sf::Vector2f delta);

	private:
		CreateAction(sf::Vector2f, OnVectorChange)

	private:
		sf::Vector2f vector;
		float threshold;
	};

}

