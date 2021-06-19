#include "Elements/Vector/Vector.h"
#include <iostream>

namespace FlatEngine::Input {

	Vector::Vector()
		: Vector(0.05f)
	{}

	Vector::Vector(float threshold)
		:
		vector(0, 0),
		threshold(threshold)
	{}

	Vector::~Vector()
	{}

	void Vector::UpdateInput(const sf::Event& event)
	{
		sf::Vector2f vectorNew = GetVectorInput(event);
		std::cout << "<Vector> X:" << vectorNew.x << " Y:" << vectorNew.y << std::endl;

		if (abs(vectorNew.x) < threshold)
		{
			vectorNew.x = 0;
		}

		if (abs(vectorNew.y) < threshold)
		{
			vectorNew.y = 0;
		}

		if (vectorNew != vector)
		{
			ChangeVector(vectorNew);
		}
	}

	void Vector::ChangeVector(sf::Vector2f value)
	{
		std::cout << "CHANGED!" << std::endl;
		vector = value;
		OnVectorChange(value);
	}

}