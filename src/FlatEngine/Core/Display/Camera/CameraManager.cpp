#include "FlatEngine/Core/Display/Camera/CameraManager.h"
#include "FlatEngine/Core/Display/Camera/Camera.h"
#include "FlatEngine/Core/Display/Main/DisplayModule.h"
#include "SFML\System.hpp"

namespace Flat::Core
{
	Camera* CameraManager::activeCamera = NULL;
	std::list<Camera*> CameraManager::cameras = {};

	void CameraManager::SetActiveCamera(Camera* value)
	{
		activeCamera = value;
	}

	void CameraManager::AddCamera(Camera* value)
	{
		if(activeCamera == NULL)
		{
			SetActiveCamera(value);
		}

		cameras.push_back(value);
	}

	void CameraManager::RemoveCamera(Camera* value)
	{
		cameras.remove(value);

		if(activeCamera == value)
		{
			SetActiveCamera(GetExistingCamera());
		}
	}

	Camera* CameraManager::GetExistingCamera()
	{
		if(!cameras.empty())
		{
			return cameras.front();
		}

		return nullptr;
	}
}