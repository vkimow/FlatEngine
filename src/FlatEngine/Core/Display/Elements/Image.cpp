#include "Elements/Image.h"

namespace FlatEngine::Display{

Image::Image(std::shared_ptr<const Core::ITransformable> origin)
	: Image(origin, Sprite())
{}

Image::Image(std::shared_ptr<const Core::ITransformable> origin, const Sprite& sprite)
	: sprite(sprite),
	DisplayElement(origin)
{}

Image::Image(std::shared_ptr<const Core::ITransformable> origin, const Sprite& sprite, size_t displayOrder)
	: sprite(sprite),
	DisplayElement(origin, displayOrder)
{}

void Image::UpdateDrawable(const Display::Camera* const camera)
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