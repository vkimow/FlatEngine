#include "Elements/Delta/DeltaPressable.h"

#include "Elements/Press\Pressable.h"
#include "Elements/Press\PressableKey.h"

namespace FlatEngine::Input
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
