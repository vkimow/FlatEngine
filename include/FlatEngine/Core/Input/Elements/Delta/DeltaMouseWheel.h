#pragma once

#include "Core/FlatEngineApi.h"
#include "Elements/Delta/Delta.h"

namespace FlatEngine::Input
{

	class FLAT_ENGINE_API DeltaMouseWheel : public Delta
	{
	public:
		DeltaMouseWheel(sf::Mouse::Wheel wheel);
		DeltaMouseWheel(DeltaMouseWheel&& value) = delete;
		DeltaMouseWheel(const DeltaMouseWheel& value) = delete;

		~DeltaMouseWheel();

	protected:
		virtual float GetDeltaInput(const sf::Event& event) override final;

	private:
		sf::Mouse::Wheel wheel;
	};

}