#pragma once

#include "FlatEngine/Core/Main/FlatEngineApi.h"
#include "SFML/Window.hpp"

namespace Flat::Core
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

