#pragma once

#include "Core/FlatEngineApi.h"
#include "SFML/Window.hpp"
#include "Main\InputElement.h"
#include "Tools/Events/Action.h"

namespace FlatEngine::Input
{

	class FLAT_ENGINE_API Delta : public InputElement
	{
	protected:
		Delta();
		Delta(float threshold);

	public:
		virtual ~Delta();

	public:
		virtual void UpdateInput(const sf::Event& event) override final;
		float GetDelta() const { return delta; }

	protected:
		virtual float GetDeltaInput(const sf::Event& event) = 0;

	private:
		void ChangeDelta(float delta);

	private:
		CreateAction(float, OnDeltaChange)

	private:
		float delta;
		float threshold;
	};

}

