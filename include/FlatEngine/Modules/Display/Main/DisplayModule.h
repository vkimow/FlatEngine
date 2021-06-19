#pragma once

#include "Main/FlatEngineApi.h"
#include "Tools/ScreenSettings.h"
#include "SFML/Graphics.hpp"
#include <vector>

namespace FlatEngine::Display
{
	class CameraManager;
	class Camera;
}

namespace FlatEngine::Display
{
	class DisplayElement;

	class FLAT_ENGINE_API DisplayModule final
	{
		friend class GameLooper;
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
		static const Display::ScreenSettings* const GetScreenSettings() { return screenSettings; }

	private:
		inline void Update(DisplayElement* element, const Display::Camera* const camera);
		inline void Draw(DisplayElement* element);

	private:
		static void AddElement(DisplayElement* element);
		static void RemoveElement(DisplayElement* element);
		static void SortElements();

	private:
		sf::RenderWindow* const renderWindow;
		Display::CameraManager* cameraManager;

	private:
		static std::vector<DisplayElement*> elements;
		static Display::ScreenSettings* screenSettings;
	};
}

