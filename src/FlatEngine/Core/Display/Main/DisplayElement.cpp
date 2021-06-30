#include "FlatEngine/Core/Display/Main/DisplayElement.h"
#include "FlatEngine/Core/Display/Main/DisplayModule.h" 
#include "FlatEngine/Core/Display/Camera/Camera.h"


namespace Flat::Core
{
	DisplayElement::DisplayElement(std::shared_ptr<const Core::ITransformable> origin)
		: DisplayElement(origin, 0)
	{}

	DisplayElement::DisplayElement(std::shared_ptr<const Core::ITransformable> origin, size_t displayOrder)
		: origin(origin), displayOrder(displayOrder)
	{
		DisplayModule::AddElement(this);
	}

	DisplayElement::~DisplayElement()
	{
		DisplayModule::RemoveElement(this);
	}

	sf::Vector2f DisplayElement::GetScreenPosition(const Camera* const camera)
	{
		return FromWorldToScreenSpace(origin->GetPosition(), camera);
	}

	void DisplayElement::SetDisplayOrder(int value)
	{
		displayOrder = value;
		DisplayModule::SortElements();
	}

	void DisplayElement::SetOrigin(std::shared_ptr<const Core::ITransformable> value)
	{
		origin = value;
	}

	std::ostream& operator<<(std::ostream& out, const DisplayElement& element)
	{
		out << "Origin:[" << *element.origin << "] "
			<< "Display Order:" << element.displayOrder;
		return out;
	}
}