#pragma once

#include "Core/FlatEngineApi.h"
#include "SFML/Window.hpp"

namespace FlatEngine::Input
{
	class FLAT_ENGINE_API InputElement
	{
	protected:
		InputElement();

	public:
		virtual ~InputElement();

	public:
		virtual void UpdateInput(const sf::Event& event) = 0;

		void SetActive(bool value);
		bool IsActive() const { return isActive; }

	private:
		bool isActive;
	};
}

