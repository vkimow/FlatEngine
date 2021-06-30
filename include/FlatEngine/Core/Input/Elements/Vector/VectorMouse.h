#pragma once

#include "FlatEngine/Core/Main/FlatEngineApi.h"
#include "FlatEngine/Core/Input/Elements/Vector/Vector.h"

namespace Flat::Core::Input
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
