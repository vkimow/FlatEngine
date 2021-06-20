#pragma once

#include "Core/FlatEngineApi.h"
#include "Main\DisplayElement.h"
#include "Tools\Sprite.h"

namespace FlatEngine::Display
{

	class FLAT_ENGINE_API Image : public DisplayElement
	{
	public:
		Image() = delete;
		Image(std::shared_ptr<const Core::ITransformable> origin);
		Image(std::shared_ptr<const Core::ITransformable> origin, const Sprite& sprite);
		Image(std::shared_ptr<const Core::ITransformable> origin, const Sprite& sprite, size_t displayOrder);

	public:
		virtual void UpdateDrawable(const Display::Camera* const camera) override final;
		virtual const sf::Drawable& GetDrawable() const override final;

	public:
		void SetSprite(const Sprite& value);
		Sprite& GetSprite() { return sprite; };

	private:
		Sprite sprite;
	};

}
