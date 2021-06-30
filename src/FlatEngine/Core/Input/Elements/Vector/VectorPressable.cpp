#include "FlatEngine/Core/Input/Elements/Vector/VectorPressable.h"
#include "FlatEngine/Core/Input/Elements/Delta/DeltaPressable.h"

namespace Flat::Core::Input 
{
	VectorPressable::VectorPressable(const std::shared_ptr<Pressable>& up,
									 const std::shared_ptr<Pressable>& down,
									 const std::shared_ptr<Pressable>& left,
									 const std::shared_ptr<Pressable>& right)
		:
		VectorDelta(std::shared_ptr<DeltaPressable>(new DeltaPressable(right, left)),
					std::shared_ptr<DeltaPressable>(new DeltaPressable(down, up)))
	{}

	VectorPressable::VectorPressable(sf::Keyboard::Key up,
									 sf::Keyboard::Key down,
									 sf::Keyboard::Key left,
									 sf::Keyboard::Key right)
		:
		VectorDelta(std::shared_ptr<DeltaPressable>(new DeltaPressable(right, left)),
					std::shared_ptr<DeltaPressable>(new DeltaPressable(down, up)))
	{}
}