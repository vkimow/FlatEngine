#pragma once

#include "Main/FlatEngineApi.h"
#include "Elements/Vector/Vector.h"

namespace FlatEngine::Input
{
	class FLAT_ENGINE_API VectorMouse : public Vector
	{
	public:
		VectorMouse();
		~VectorMouse() {};

	protected:
		virtual sf::Vector2f GetVectorInput(const sf::Event& event) override final;

	private:
		sf::Vector2f mousePosition;
	};

}
