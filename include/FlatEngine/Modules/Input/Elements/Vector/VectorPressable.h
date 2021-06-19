#pragma once

#include "Main/FlatEngineApi.h"
#include "Elements/Vector/VectorDelta.h"


namespace FlatEngine::Input
{
	class Pressable;

	class FLAT_ENGINE_API VectorPressable : public VectorDelta
	{
	public:
		VectorPressable() = delete;
		VectorPressable(const std::shared_ptr<Pressable>& up,
						const std::shared_ptr<Pressable>& down,
						const std::shared_ptr<Pressable>& left,
						const std::shared_ptr<Pressable>& right);

		VectorPressable(sf::Keyboard::Key up,
						sf::Keyboard::Key down,
						sf::Keyboard::Key left,
						sf::Keyboard::Key right);

		~VectorPressable() {};
	};
}