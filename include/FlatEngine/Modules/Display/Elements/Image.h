#pragma once

#include "FlatEngineApi.h"
#include "Modules\Display\DisplayElement.h"
#include "Modules\Display\Tools\Sprite.h"

namespace FlatEngine::Core::Modules::Display
{

	class FLAT_ENGINE_API Image : public DisplayElement
	{
	public:
		Image() = delete;
		Image(std::shared_ptr<const Simulation::ITransformable> origin);
		Image(std::shared_ptr<const Simulation::ITransformable> origin, const Sprite& sprite);
		Image(std::shared_ptr<const Simulation::ITransformable> origin, const Sprite& sprite, size_t displayOrder);

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
