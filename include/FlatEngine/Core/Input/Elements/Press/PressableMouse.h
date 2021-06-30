#pragma once

#include "FlatEngine/Core/Main/FlatEngineApi.h"
#include "FlatEngine/Core/Input/Elements/Press/Pressable.h"

namespace Flat::Core::Input
{

	class FLAT_ENGINE_API PressableMouse : public Pressable
	{
	public:
		PressableMouse() = delete;
		PressableMouse(PressableMouse&& inputKeyElement) = delete;
		PressableMouse(const PressableMouse& inputKeyElement) = delete;

		PressableMouse(sf::Mouse::Button button);
		~PressableMouse();

	protected:
		virtual bool GetPressInput(const sf::Event& event) override final;

	private:
		sf::Mouse::Button button;
	};

}