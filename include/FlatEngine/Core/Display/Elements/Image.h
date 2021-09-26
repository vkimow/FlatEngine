#pragma once

#include "FlatEngine/Core/Main/FlatEngineApi.h"
#include "FlatEngine/Core/Display/Main/DisplayElement.h"
#include "FlatEngine/Core/Display/Tools/Sprite.h"
#include "FlatEngine/Core/Transform/ITransformable.h"

namespace Flat::Core
{

	class FLAT_ENGINE_API Image : public DisplayElement
	{
	public:
		Image();
		Image(const Sprite& sprite);
		Image(const Sprite& sprite, size_t displayOrder);

	public:
		virtual void UpdateDrawable(const Camera* const camera) override final;
		virtual const sf::Drawable& GetDrawable() const override final;

	public:
		void SetSprite(const Sprite& value);
		Sprite& GetSprite() { return sprite; };

	private:
		Sprite sprite;
	};

}
