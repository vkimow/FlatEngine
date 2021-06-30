#include "FlatEngine/Core/Display/Elements/Animation.h"
#include "FlatEngine/Core/Time/TimeModule.h"

namespace Flat::Core
{
	Animation::Animation(std::shared_ptr<const ITransformable> origin, const std::vector<Sprite>& sprites)
		: Animation(origin, sprites, 1)
	{}

	Animation::Animation(std::shared_ptr<const ITransformable> origin, const std::vector<Sprite>& sprites, float spritesPerSecond)
		: Animation(origin, sprites, spritesPerSecond, 0)
	{}

	Animation::Animation(std::shared_ptr<const ITransformable> origin, const std::vector<Sprite>& sprites, FrameSpeed animationSpeed)
		: Animation(origin, sprites, animationSpeed, 0)
	{}

	Animation::Animation(std::shared_ptr<const ITransformable> origin, const std::vector<Sprite>& sprites, float spritesPerSecond, size_t displayOrder)
		: Animation(origin, sprites, (FrameSpeed)spritesPerSecond, displayOrder)
	{}

	Animation::Animation(std::shared_ptr<const ITransformable> origin, const std::vector<Sprite>& sprites, FrameSpeed animationSpeed, size_t displayOrder)
		:
		sprites(sprites),
		animationSpeed(animationSpeed),
		currentSpriteIndex(0),
		timeToChageSprite(animationSpeed.GetFrameTime()),
		DisplayElement(origin, displayOrder)
	{}

	void Animation::UpdateDrawable(const Camera* const camera)
	{
		timeToChageSprite -= Core::TimeModule::GetDeltaTime();

		if(timeToChageSprite <= 0)
		{
			++currentSpriteIndex;
			currentSpriteIndex %= sprites.size();	
			sf::Vector2f screenPosition = GetScreenPosition(camera);
			Sprite* currenSprite = &sprites[currentSpriteIndex];
			currenSprite->sfmlSprite.setPosition(std::move(screenPosition));

			timeToChageSprite = animationSpeed.GetFrameTime();
		}
	}

	const sf::Drawable& Animation::GetDrawable() const
	{
		return sprites[currentSpriteIndex].sfmlSprite;
	}

	void Animation::SetAnimationSpeed(const FrameSpeed& value)
	{
		animationSpeed = value;
	}

	void Animation::SetCurrentSpriteIndex(size_t value)
	{
		currentSpriteIndex = value;
	}
}