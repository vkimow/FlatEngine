#pragma once

#include "Core/FlatEngineApi.h"
#include "SFML/Window.hpp"
#include "Main\InputElement.h"
#include "Tools/Events\Action.h"
#include "Tools/Events\Function.h"

namespace FlatEngine::Input
{

	class FLAT_ENGINE_API Pressable : public InputElement
	{
	protected:
		Pressable();

	public:
		virtual ~Pressable();

	public:
		virtual void UpdateInput(const sf::Event& event) override final;
		bool IsPressed() const { return isPressed; }

	protected:
		virtual bool GetPressInput(const sf::Event& event) = 0;

	private:
		void Press();
		void Release();

	private:
		CreateAction(void, OnPress)
		CreateAction(void, OnRelease)

	private:
		bool isPressed;
	};

}

