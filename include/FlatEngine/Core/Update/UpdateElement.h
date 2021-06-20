#pragma once

#include "Core/FlatEngineApi.h"

namespace FlatEngine::Core
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
		void SetActive(bool value);

	private:
		bool isActive;
		size_t updateOrder;
	};
}
