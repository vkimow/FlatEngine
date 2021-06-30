#pragma once

#include "FlatEngine/Core/Main/FlatEngineApi.h"
#include <vector>
#include "FlatEngine/Core/Main/Events/Function.h"

namespace Flat::Core
{
	template <typename Member, typename Type>
	class FLAT_ENGINE_API MemberFunction : public Function<Type>
	{
	private:
		typedef Type T;
		typedef void(Member::* FunctionPointer)(T);
		typedef std::function<void(T)> StdFunction;
		typedef std::vector<std::pair<FunctionPointer, MemberFunction>> FunctionsMap;
		typedef std::unordered_map<Member*, FunctionsMap> MemberFunctionsMap;

#pragma region Constructors
	private:
		MemberFunction(StdFunction function)
			: Function<Type>(function)
		{}

	public:
		MemberFunction() {}

		MemberFunction(const MemberFunction& rhs)
			: Function<Type>(rhs)
		{}

		MemberFunction(MemberFunction&& rhs) noexcept
			: Function<Type>(std::move(rhs))
		{}

		MemberFunction& operator=(const MemberFunction& rhs) {}
		MemberFunction& operator=(MemberFunction&& rhs) noexcept {}

	public:
		MemberFunction(Member* member, FunctionPointer function)
		{
			if (ContainsMemberFunction(member, function))
			{
				std::cout << "Contains Member Function!";
				auto referenceFunction = GetMemberFunction(member, function);
				this->function = referenceFunction.function;
				this->id = referenceFunction.id;
				return;
			}

			auto bindedFunction = std::bind(function, member, std::placeholders::_1);
			this->function = bindedFunction;
			this->id = FunctionIdGetter<T>::GetNextId();

			AddMemberFunction(member, function, *this);
		}

		static MemberFunction Create(Member* member, FunctionPointer function)
		{
			if (ContainsMemberFunction(member, function))
			{
				std::cout << "Contains Member Function!";
				return GetMemberFunction(member, function);
			}

			auto bindedFunction = std::bind(function, member, std::placeholders::_1);
			auto memberFunction = MemberFunction(bindedFunction);

			AddMemberFunction(member, function, memberFunction);
			return memberFunction;
		}
#pragma endregion

	private:
		static bool ContainsMemberFunctionContainer(Member* member)
		{
			return memberFunctions.find(member) != memberFunctions.end();
		}

		static bool ContainsMemberFunction(Member* member, FunctionPointer function)
		{
			if (!ContainsMemberFunctionContainer(member))
				return false;

			auto& container = memberFunctions[member];

			for (int i = 0; i < container.size(); ++i)
			{
				if (container[i].first == function)
				{
					return true;
				}
			}

			return false;
		}

		static size_t GetMemberFunctionId(Member* member, FunctionPointer function)
		{
			if (!ContainsMemberFunctionContainer(member))
				throw std::exception("doesn't contain member function");

			auto& container = memberFunctions[member];

			for (int i = 0; i < container.size(); ++i)
			{
				if (container[i].first == function)
				{
					return i;
				}
			}

			throw std::exception("doesn't contain member function");
		}

		static void CreateMemberFunctionContainer(Member* member)
		{
			memberFunctions.insert(std::make_pair(member, FunctionsMap()));
		}

		static void AddMemberFunction(Member* member, FunctionPointer function, MemberFunction memberFunction)
		{
			auto pair = std::make_pair(function, memberFunction);

			if (!ContainsMemberFunctionContainer(member))
			{
				CreateMemberFunctionContainer(member);
			}

			FunctionsMap& container = memberFunctions[member];
			container.push_back(std::move(pair));
		}

		static const MemberFunction& GetMemberFunction(Member* member, FunctionPointer function)
		{
			if (!ContainsMemberFunction(member, function))
				throw std::exception("Have no funciton!");

			int id = GetMemberFunctionId(member, function);

			return memberFunctions[member][id].second;
		}

	private:
		static MemberFunctionsMap memberFunctions;
	};

	template<typename Member, typename Type>
	std::unordered_map<Member*, std::vector<std::pair<void(Member::*)(Type), MemberFunction<Member, Type>>>> MemberFunction<Member, Type>::memberFunctions = { };
}