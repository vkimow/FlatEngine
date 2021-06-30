#pragma once

#include "FlatEngine/Core/Main/FlatEngineApi.h"
#include "FlatEngine/Core/Display/Tools/ScreenSettings.h"
#include "SFML/Graphics.hpp"
#include <vector>

namespace Flat::Engine
{
	class GameLooper;
}

namespace Flat::Core
{
	class DisplayElement;
	class CameraManager;
	class Camera;

	class FLAT_ENGINE_API DisplayModule final
	{
		friend class Engine::GameLooper;
		friend class DisplayElement;

	private:
		DisplayModule(sf::RenderWindow* renderWindow);
		DisplayModule() = delete;
		DisplayModule(DisplayModule&& displayModule) = delete;
		DisplayModule(const DisplayModule& displayModule) = delete;
		~DisplayModule();

	public:
		void Update();

	public:
		static const ScreenSettings* const GetScreenSettings() { return screenSettings; }

	private:
		inline void Update(DisplayElement* element, const Camera* const camera);
		inline void Draw(DisplayElement* element);

	private:
		static void AddElement(DisplayElement* element);
		static void RemoveElement(DisplayElement* element);
		static void SortElements();

	private:
		sf::RenderWindow* const renderWindow;
		CameraManager* cameraManager;

	private:
		static std::vector<DisplayElement*> elements;
		static ScreenSettings* screenSettings;
	};
}

