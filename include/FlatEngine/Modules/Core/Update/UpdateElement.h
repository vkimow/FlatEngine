#pragma once

#include "FlatEngineApi.h"

namespace FlatEngine::Core::Modules
{
	class FLAT_ENGINE_API UpdateElement
	{
	public:
		UpdateElement();
		UpdateElement(int updateOrder);
		virtual ~UpdateElement();

	public:
		virtual void Update() = 0;

		int GetUpdateOrder() const { return updateOrder; }
		void SetUpdateOrder(int value);

		bool IsActive() const { return isActive; }
		void SetActive(bool value);

	private:
		bool isActive;
		int updateOrder;
	};
}
