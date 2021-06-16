#include "DeltaPressable.h"

#include "Modules\Input\InputElements\Press\Pressable.h"
#include "Modules\Input\InputElements\Press\PressableKey.h"

namespace FlatEngine::Core::Modules::Input
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
