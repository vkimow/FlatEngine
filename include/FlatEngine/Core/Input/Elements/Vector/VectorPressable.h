#pragma once

#include "FlatEngine/Core/Main/FlatEngineApi.h"
#include "FlatEngine/Core/Input/Elements/Vector/VectorDelta.h"

namespace Flat::Core::Input
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