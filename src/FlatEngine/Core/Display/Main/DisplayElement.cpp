#include "Main/DisplayElement.h"
#include "Main/DisplayModule.h" 
#include "Camera/Camera.h"

namespace FlatEngine::Display
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

	sf::Vector2f DisplayElement::GetScreenPosition(const Display::Camera* const camera)
	{
		return Display::FromWorldToScreenSpace(origin->GetPosition(), camera);
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