#pragma once

#include "Core/FlatEngineApi.h"
#include <list>

namespace FlatEngine::Display
{
	class Camera;

	class FLAT_ENGINE_API CameraManager
	{
		friend class Camera;

	public:
		CameraManager() {};
		~CameraManager() {};

	public:
		Camera* GetActiveCamera() { return activeCamera; }

	private:
		static void SetActiveCamera(Camera* value);
		static void AddCamera(Camera* value);
		static void RemoveCamera(Camera* value);
		static Camera* GetExistingCamera();

	private:
		static Camera* activeCamera;
		static std::list<Camera*> cameras;
	};
}