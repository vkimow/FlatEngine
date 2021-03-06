#pragma once

#include "FlatEngine/Core/Main/FlatEngineApi.h"
#include "FlatEngine/Core/Input/Elements/Delta/Delta.h"

namespace Flat::Core::Input
{
	class  Pressable;

	class FLAT_ENGINE_API DeltaPressable : public Delta
	{
	public:
		DeltaPressable(const std::shared_ptr<Pressable>& positive, const std::shared_ptr<Pressable>& negative);
		DeltaPressable(sf::Keyboard::Key positive, sf::Keyboard::Key negative);
		DeltaPressable() = delete;

		~DeltaPressable() {};

	protected:
		virtual float GetDeltaInput(const sf::Event& event) override final;

	private:
		std::shared_ptr<Pressable> positive;
		std::shared_ptr<Pressable> negative;
	};

}