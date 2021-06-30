#pragma once

#include "FlatEngine/Core/Main/FlatEngineApi.h"
#include "SFML/System.hpp"

namespace Flat::Core
{
	class FLAT_ENGINE_API TimeModule
	{
	public:
		TimeModule();
		TimeModule(const TimeModule& timeModule) = delete;
		TimeModule(TimeModule&& timeModule) = delete;
		TimeModule& operator=(const TimeModule& timeModule) = delete;
		TimeModule& operator=(TimeModule&& timeModule) = delete;

	public:
		void Update();

	public:
		static float GetDeltaTime() { return deltaTime; }

	private:
		static float deltaTime;
		sf::Clock clock;
	};
}