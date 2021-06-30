#pragma once

#include "FlatEngine/Core/Main/FlatEngineApi.h"
#include <unordered_map>
#include "FlatEngine/Core/Main/Events/Function.h"

namespace Flat::Core
{
#pragma region Create Macros
#define CreateAction(type, name)\
	public:\
\
		void AddListener##name(Flat::Core::Function<type> function)\
		{\
			##name += function;\
		}\
\
		void RemoveListener##name(Flat::Core::Function<type> function)\
		{\
			##name -= function;\
		}\
\
		void RemoveListener##name(size_t id)\
		{\
			##name -= id;\
		}\
\
	private:\
		Flat::Core::Action<type> ##name;
#pragma endregion

#pragma region TEMPLATE
	template <typename Type>
	class FLAT_ENGINE_API Action
	{
	private:
		typedef Type T;
		typedef Function<T> FunctionType;

	public:
		Action() {};
		~Action() {};

#pragma region Contsructors
		Action(const Action& rhs)
			: listeners(rhs.listeners)
		{}

		Action(Action&& rhs) noexcept
			: listeners(std::move(rhs.listeners))
		{}

		Action(const FunctionType& listener)
		{
			AddListener(listener);
		};

		Action(FunctionType&& listener)
		{
			AddListener(std::move(listener));
		};
#pragma endregion

#pragma region operator=
		Action & operator=(const Action& rhs)
		{
			listeners = rhs.listeners;
			return *this;
		};

		Action& operator=(Action&& rhs) noexcept
		{
			listeners = std::move(rhs.listeners);
			return *this;
		};

		Action& operator=(const FunctionType& rhs)
		{
			listeners.clear();
			AddListener(rhs);
			return *this;
		};

		Action& operator=(FunctionType&& rhs)
		{
			listeners.clear();
			AddListener(std::move(rhs));
			return *this;
		};
#pragma endregion

	public:
		Action& operator+=(const Action& rhs) { AddListener(rhs); return *this; }
		Action& operator+=(const FunctionType& rhs) { AddListener(rhs); return *this; }

		Action& operator-=(const Action& rhs) { RemoveListener(rhs); return *this; }
		Action& operator-=(const FunctionType& rhs) { RemoveListener(rhs); return *this; }
		Action& operator-=(size_t id) { RemoveListener(id); return *this; }

		void operator()(const T& value) { RiseEvent(value); }
		//void operator()() { RiseEvent(); }

	private:
		void RemoveListener(const Action& action)
		{
			for (auto const& listener : action.listeners)
			{
				RemoveListener(listener.second);
			}
		}

		void RemoveListener(const FunctionType& listener)
		{
			RemoveListener(listener.GetId());
		}

		void RemoveListener(size_t id)
		{
			if (listeners.find(id) == listeners.end())
			{
				throw std::exception("Doesn't contain this listener");
			}

			listeners.erase(id);
		}



		void AddListener(const Action& action)
		{
			for (auto const& listener : action.listeners)
			{
				AddListener(listener.second);
			}
		}

		void AddListener(const FunctionType& listener)
		{
			if (listeners.find(listener.GetId()) != listeners.end())
			{
				throw std::exception("Already contain this listener");
			}

			auto pair = std::make_pair(listener.GetId(), listener);
			listeners.insert(std::move(pair));
		}



		//void RiseEvent()
		//{
		//	for (auto& listener : listeners)
		//	{
		//		listener.second.Call();
		//	}
		//}

		void RiseEvent(const T& value)
		{
			for (auto& listener : listeners)
			{
				listener.second.Call(value);
			}
		}

	private:
		std::unordered_map<size_t, FunctionType> listeners;
	};
#pragma endregion

#pragma region VOID
	template <>
	class FLAT_ENGINE_API Action<void>
	{
	private:
		typedef void T;
		typedef Function<T> FunctionType;

	public:
		Action() {};
		~Action() {};

#pragma region Contsructors
		Action(const Action& rhs)
			: listeners(rhs.listeners)
		{}

		Action(Action&& rhs) noexcept
			: listeners(std::move(rhs.listeners))
		{}

		Action(const FunctionType& listener)
		{
			AddListener(listener);
		};

		Action(FunctionType&& listener)
		{
			AddListener(std::move(listener));
		};
#pragma endregion

#pragma region operator=
		Action & operator=(const Action& rhs)
		{
			listeners = rhs.listeners;
			return *this;

		};

		Action& operator=(Action&& rhs) noexcept
		{
			listeners = std::move(rhs.listeners);
			return *this;

		};

		Action& operator=(const FunctionType& rhs)
		{
			listeners.clear();
			AddListener(rhs);
			return *this;
		};

		Action& operator=(FunctionType&& rhs)
		{
			listeners.clear();
			AddListener(std::move(rhs));
			return *this;
		};
#pragma endregion

	public:
		Action& operator+=(const Action& rhs) { AddListener(rhs); return *this; }
		Action& operator+=(const FunctionType& rhs) { AddListener(rhs); return *this; }

		Action& operator-=(const Action& rhs) { RemoveListener(rhs); return *this; }
		Action& operator-=(const FunctionType& rhs) { RemoveListener(rhs); return *this; }
		Action& operator-=(size_t id) { RemoveListener(id); return *this; }

		void operator()() { RiseEvent(); }

	private:
		void RemoveListener(const Action& action)
		{
			for (auto const& listener : action.listeners)
			{
				RemoveListener(listener.second);
			}
		}

		void RemoveListener(const FunctionType& listener)
		{
			RemoveListener(listener.GetId());
		}

		void RemoveListener(size_t id)
		{
			if (listeners.find(id) == listeners.end())
			{
				throw std::exception("Doesn't contain this listener");
			}

			listeners.erase(id);
		}

		void AddListener(const Action& action)
		{
			for (auto const& listener : action.listeners)
			{
				AddListener(listener.second);
			}
		}

		void AddListener(const FunctionType& listener)
		{
			if (listeners.find(listener.GetId()) != listeners.end())
			{
				throw std::exception("Already contain this listener");
			}

			auto pair = std::make_pair(listener.GetId(), listener);
			listeners.insert(std::move(pair));
		}

		void RiseEvent()
		{
			for (auto& listener : listeners)
			{
				listener.second.Call();
			}
		}

	private:
		std::unordered_map<size_t, FunctionType> listeners;
	};
#pragma endregion
}
