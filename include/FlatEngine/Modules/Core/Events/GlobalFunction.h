#pragma once

#include "Main/FlatEngineApi.h"
#include <iostream>
#include <unordered_map>
#include <functional>
#include "Events/Function.h"

namespace FlatEngine::Core
{
	template <typename Type>
	class FLAT_ENGINE_API GlobalFunction : public Function<Type>
	{
	private:
		typedef Type T;
		typedef void(*FunctionPointer)(T);
		typedef std::function<void(T)> StdFunction;
		typedef std::unordered_map<FunctionPointer, GlobalFunction> GlobalFunctionsMap;

#pragma region Constructors
	private:
		GlobalFunction(StdFunction function)
			: Function<Type>(function)
		{}

	public:
		GlobalFunction() {}

		GlobalFunction(const GlobalFunction& rhs)
			: Function<Type>(rhs)
		{}

		GlobalFunction(GlobalFunction&& rhs) noexcept
			: Function<Type>(std::move(rhs))
		{}

		GlobalFunction& operator=(const GlobalFunction& rhs) {}
		GlobalFunction& operator=(GlobalFunction&& rhs) noexcept {}

	public:
		GlobalFunction (FunctionPointer function)
		{
			if (ContainsGlobalFunction(function))
			{
				std::cout << "Contains Global Function!";
				auto referenceFunction = GetGlobalFunction(function);
				this->function = referenceFunction.function;
				this->id = referenceFunction.id;
				return;
			}

			auto stdFunction = std::function(function);
			this->function = stdFunction;
			this->id = FunctionIdGetter<T>::GetNextId();

			AddGlobalFunction(function, *this);
		}

		static GlobalFunction Create(FunctionPointer function)
		{
			if (ContainsGlobalFunction(function))
			{
				std::cout << "Contains Global Function!";
				return GetGlobalFunction(function);
			}

			auto stdFunction = std::function(function);
			auto globalFunction = GlobalFunction(function);

			AddGlobalFunction(function, globalFunction);
			return globalFunction;
		}
#pragma endregion

	private:
		static bool ContainsGlobalFunction(FunctionPointer function)
		{
			return globalFunctions.find(function) != globalFunctions.end();
		}

		static void AddGlobalFunction(FunctionPointer function, const GlobalFunction& globalFunction)
		{
			auto pair = std::make_pair(function, globalFunction);
			globalFunctions.insert(std::move(pair));
		}

		static const GlobalFunction& GetGlobalFunction(FunctionPointer function)
		{
			if (!ContainsGlobalFunction(function))
			{
				throw std::exception("Have no function!");
			}

			return globalFunctions[function];
		}

	private:
		static GlobalFunctionsMap globalFunctions;
	};

	template<typename Type>
	std::unordered_map<void(*)(Type), GlobalFunction<Type>> GlobalFunction<Type>::globalFunctions = { };
}