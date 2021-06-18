#pragma once

#include "FlatEngineApi.h"
#include <functional>

namespace FlatEngine::Core::Tools::Events
{
	template<typename Type>
	class FLAT_ENGINE_API FunctionIdGetter
	{
	public:
		static size_t GetNextId() { return instanceCounter++; }

	private:
		static size_t instanceCounter;
	};

	template<typename Type>
	size_t FunctionIdGetter<Type>::instanceCounter = 0;
}