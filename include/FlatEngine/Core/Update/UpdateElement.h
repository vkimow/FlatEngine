#pragma once

#include "FlatEngine/Core/Main/FlatEngineApi.h"

namespace Flat::Core
{
	class FLAT_ENGINE_API UpdateElement
	{
	public:
		UpdateElement();
		UpdateElement(size_t updateOrder);
		virtual ~UpdateElement();

	public:
		virtual void Update() = 0;

		size_t GetUpdateOrder() const { return updateOrder; }
		void SetUpdateOrder(size_t value);

		bool IsActive() const { return isActive; }
		void EnableAutoUpdate(bool value);

	private:
		bool isActive;
		size_t updateOrder;
	};
}
