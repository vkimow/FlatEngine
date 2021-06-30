#pragma once

#include "FlatEngine/Core/Main/FlatEngineApi.h"
#include "SFML/Window.hpp"
#include "FlatEngine/Core/Input/Main/InputElement.h"
#include "FlatEngine/Core/Main/Events/Action.h"

namespace Flat::Core::Input
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

