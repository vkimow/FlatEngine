#include "FlatEngine/Core/Input/Elements/Delta/DeltaPressable.h"

#include "FlatEngine/Core/Input/Elements/Press\Pressable.h"
#include "FlatEngine/Core/Input/Elements/Press\PressableKey.h"

namespace Flat::Core::Input
{
	DeltaPressable::DeltaPressable(const std::shared_ptr<Pressable>& positive, const std::shared_ptr<Pressable>& negative)
		:
		positive(positive),
		negative(negative)
	{}

	DeltaPressable::DeltaPressable(sf::Keyboard::Key positiveKey, sf::Keyboard::Key negativeKey)
		:
		positive(new PressableKey(positiveKey)),
		negative(new PressableKey(negativeKey))
	{}

	float DeltaPressable::GetDeltaInput(const sf::Event& event)
	{
		return (float)(positive->IsPressed() - negative->IsPressed());
	}
}
