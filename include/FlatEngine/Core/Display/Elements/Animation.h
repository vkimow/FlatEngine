#pragma once

#include "FlatEngine/Core/Main/FlatEngineApi.h"
#include "FlatEngine/Core/Display/Main/DisplayElement.h"
#include "FlatEngine/Core/Display/Tools/Sprite.h"
#include "FlatEngine/Core/Display/Tools/FrameSpeed.h"
#include <vector>

namespace Flat::Core
{
	class FLAT_ENGINE_API Animation : DisplayElement
	{
	public:
		Animation() = delete;
		Animation(const std::vector<Sprite>& sprites);
		Animation(const std::vector<Sprite>& sprites, float spritesPerSecond);
		Animation(const std::vector<Sprite>& sprites, FrameSpeed animationSpeed);
		Animation(const std::vector<Sprite>& sprites, float spritesPerSecond, size_t diplayOrder);
		Animation(const std::vector<Sprite>& sprites, FrameSpeed animationSpeed, size_t displayOrder);


	public:
		virtual void UpdateDrawable(const Camera* const camera) override final;
		virtual const sf::Drawable& GetDrawable() const override final;

	public:
		void SetAnimationSpeed(const FrameSpeed& value);
		void SetCurrentSpriteIndex(size_t value);

		FrameSpeed GetAnimationSpeed() const { return animationSpeed; }
		size_t GetCurrentSpriteIndex() const { return currentSpriteIndex; }

	private:
		std::vector<Sprite> sprites;
		FrameSpeed animationSpeed;
		float timeToChageSprite;
		size_t currentSpriteIndex;
	};
}