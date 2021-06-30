#include "FlatEngine/Core/Display/Tools/Sprite.h"

namespace Flat::Core
{
	Sprite::Sprite()
		: Sprite(std::shared_ptr<sf::Texture>())
	{}

	Sprite::Sprite(std::shared_ptr<sf::Texture> texture)
		: Sprite(texture, sf::IntRect())
	{}

	Sprite::Sprite(std::shared_ptr<sf::Texture> texture, sf::IntRect rectangle)
		: texture(texture), sfmlSprite(*texture, rectangle)
	{
		sfmlSprite.setPosition(100, 100);
	}

	void Sprite::SetTexture(std::shared_ptr<sf::Texture> texture, bool resetRect)
	{
		this->texture = texture;
		sfmlSprite.setTexture(*texture, resetRect);
	}

	void Sprite::SetTexture(std::shared_ptr<sf::Texture> texture, sf::IntRect rectangle)
	{
		this->texture = texture;
		sfmlSprite.setTexture(*texture);
		sfmlSprite.setTextureRect(rectangle);
	}

	void Sprite::SetTextureRect(const sf::IntRect& rectangle)
	{
		sfmlSprite.setTextureRect(rectangle);
	}

	void Sprite::SetColor(const sf::Color& color)
	{
		sfmlSprite.setColor(color);
	}

}