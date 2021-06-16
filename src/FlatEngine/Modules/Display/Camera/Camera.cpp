#include "Camera.h"
#include "CameraManager.h"
#include "Modules\Display\DisplayModule.h"


namespace FlatEngine::Core::Modules::Display
{
	FlatEngine::Core::Modules::Display::Camera::Camera()
		: Camera(std::shared_ptr<Simulation::ITransformable>())
	{}

	FlatEngine::Core::Modules::Display::Camera::Camera(std::shared_ptr<Simulation::ITransformable> origin)
		: origin(origin), zoom(1)
	{
		CameraManager::AddCamera(this);
	}

	FlatEngine::Core::Modules::Display::Camera::~Camera()
	{
		CameraManager::RemoveCamera(this);
	}

	void FlatEngine::Core::Modules::Display::Camera::SetCameraActive()
	{
		CameraManager::SetActiveCamera(this);
	}

	bool FlatEngine::Core::Modules::Display::Camera::IsCameraActive()
	{
		return CameraManager::activeCamera == this;
	}

	void FlatEngine::Core::Modules::Display::Camera::SetOrigin(std::shared_ptr<Simulation::ITransformable> value)
	{
		origin = value;
	}

	void FlatEngine::Core::Modules::Display::Camera::SetZoom(float value)
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