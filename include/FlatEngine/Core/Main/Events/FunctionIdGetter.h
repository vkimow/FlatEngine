#pragma once

#include "FlatEngine/Core/Main/FlatEngineApi.h"
#include <functional>

namespace Flat::Core
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