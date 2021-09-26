#include "FlatEngine/Core/Display/Elements/Image.h"

namespace Flat::Core{

Image::Image()
	: Image(Sprite())
{}

Image::Image(const Sprite& sprite)
	: Image(sprite, 0)
{}

Image::Image(const Sprite& sprite, size_t displayOrder)
	: sprite(sprite),
	DisplayElement(displayOrder)
{}

void Image::UpdateDrawable(const Camera* const camera)
{
	sf::Vector2f screenPosition(GetScreenPosition(camera));
	sprite.sfmlSprite.setPosition(std::move(screenPosition));
}

const sf::Drawable& Image::GetDrawable() const
{
	return sprite.sfmlSprite;
}

void Image::SetSprite(const Sprite & value)
{
	sprite = value;
}

}