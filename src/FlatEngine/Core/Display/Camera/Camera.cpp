#include "Camera/Camera.h"
#include "Camera/CameraManager.h"
#include "Main/DisplayModule.h"

namespace FlatEngine::Display
{
	Camera::Camera()
		: Camera(std::shared_ptr<Core::ITransformable>())
	{}

	Camera::Camera(std::shared_ptr<Core::ITransformable> origin)
		: origin(origin), zoom(1)
	{
		CameraManager::AddCamera(this);
	}

	Camera::~Camera()
	{
		CameraManager::RemoveCamera(this);
	}

	void Camera::SetCameraActive()
	{
		CameraManager::SetActiveCamera(this);
	}

	bool Camera::IsCameraActive()
	{
		return CameraManager::activeCamera == this;
	}

	void Camera::SetOrigin(std::shared_ptr<Core::ITransformable> value)
	{
		origin = value;
	}

	void Camera::SetZoom(float value)
	{
		zoom = value;
	}

	sf::Vector2f FromWorldToCameraSpace(const sf::Vector2f& coords, const Camera* const camera)
	{
		return coords - camera->GetOrigin()->GetPosition();
	}

	sf::Vector2f FromCameraToWorldSpace(const sf::Vector2f& coords, const Camera* const camera)
	{
		return coords + camera->GetOrigin()->GetPosition();
	}

	sf::Vector2f FromCameraToScreenSpace(const sf::Vector2f& coords, const Camera* const camera)
	{
		return (coords / camera->GetZoom()) + DisplayModule::GetScreenSettings()->GetHalfResolution();
	}

	sf::Vector2f FromScreenToCameraSpace(const sf::Vector2f& coords, const Camera* const camera)
	{
		return (coords - DisplayModule::GetScreenSettings()->GetHalfResolution()) * camera->GetZoom();
	}

	sf::Vector2f FromWorldToScreenSpace(const sf::Vector2f& coords, const Camera* const camera)
	{
		return FromCameraToScreenSpace(FromWorldToCameraSpace(coords, camera), camera);
	}

	sf::Vector2f FromScreenToWorldSpace(const sf::Vector2f& coords, const Camera* const camera)
	{
		return FromCameraToWorldSpace(FromScreenToCameraSpace(coords, camera), camera);
	}
}