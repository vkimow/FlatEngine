#include "FlatEngine/Core/Display/Main/DisplayElement.h"
#include "FlatEngine/Core/Display/Main/DisplayModule.h" 
#include "FlatEngine/Core/Display/Camera/Camera.h"


namespace Flat::Core
{
	DisplayElement::DisplayElement()
		: DisplayElement(0)
	{}

	DisplayElement::DisplayElement(size_t displayOrder)
		: displayOrder(displayOrder),
		Objects::ObjectComponent()
	{
	}

	DisplayElement::~DisplayElement()
	{
		DisplayModule::RemoveElement(this);
	}

	sf::Vector2f DisplayElement::GetScreenPosition(const Camera* const camera)
	{
		return FromWorldToScreenSpace(GetGameObject()->GetTransform()->GetPosition(), camera);
	}

	void DisplayElement::SetDisplayOrder(int value)
	{
		displayOrder = value;
		DisplayModule::SortElements();
	}

	std::ostream& operator<<(std::ostream& out, const DisplayElement& element)
	{
		out << "Origin:[" << *(element.GetGameObject()->GetTransform()) << "] "
			<< "Display Order:" << element.displayOrder;
		return out;
	}
}