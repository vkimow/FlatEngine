#pragma once
#include "Core.h"
#include <string>

namespace FlatEngine::Core
{

	class FLAT_ENGINE_API App
	{
	public:
		App();
		App(std::string appName, unsigned int width, unsigned int height);
		~App();

		App(const App& rhs) = delete;
		App(App&& rhs) = delete;
		App& operator=(const App& rhs) = delete;
		App& operator=(App&& rhs) = delete;

	public:
		void Run();
		void Quit();

	private:
		static bool isAppActive;
	};
}
