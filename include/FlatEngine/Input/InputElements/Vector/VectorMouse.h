#pragma once

#include <Core.h>
#include "Vector.h"

namespace FlatEngine::Core::Modules::Input
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
