#pragma once

#include "FlatEngineApi.h"
#include "Modules\Display\DisplayElement.h"
#include "Modules\Display\Tools\Sprite.h"
#include "Modules\Display\Tools\FrameSpeed.h"
#include <vector>

namespace FlatEngine::Core::Modules::Display
{
	class FLAT_ENGINE_API Animation : DisplayElement
	{
	public:
		Animation() = delete;
		Animation(std::shared_ptr<const Simulation::ITransformable> origin, const std::vector<Sprite>& sprites);
		Animation(std::shared_ptr<const Simulation::ITransformable> origin, const std::vector<Sprite>& sprites, float spritesPerSecond);
		Animation(std::shared_ptr<const Simulation::ITransformable> origin, const std::vector<Sprite>& sprites, FrameSpeed animationSpeed);
		Animation(std::shared_ptr<const Simulation::ITransformable> origin, const std::vector<Sprite>& sprites, float spritesPerSecond, size_t diplayOrder);
		Animation(std::shared_ptr<const Simulation::ITransformable> origin, const std::vector<Sprite>& sprites, FrameSpeed animationSpeed, size_t displayOrder);


	public:
		virtual void UpdateDrawable(const Display::Camera* const camera) override final;
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