#pragma once

#include "FlatEngineApi.h"
#include <vector>

namespace FlatEngine::Core::Modules
{
	class UpdateElement;

	class FLAT_ENGINE_API UpdateModule
	{
		friend class GameLooper;
		friend class UpdateElement;

	public:
		UpdateModule();
		UpdateModule(UpdateModule&& updateModule) = delete;

	public:
		void Update();

	private:
		static std::vector<UpdateElement*> elements;

	private:
		static void AddElement(UpdateElement* element);
		static void RemoveElement(UpdateElement* element);
		static void SortElements();
	};
}
