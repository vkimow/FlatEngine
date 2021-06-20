#pragma once

#include "Core/FlatEngineApi.h"
#include "Transform/ITransformable.h"

namespace FlatEngine::Display
{
	class FLAT_ENGINE_API Camera
	{

	public:
		Camera();
		Camera(std::shared_ptr<Core::ITransformable> origin);
		~Camera();

	public:
		void SetCameraActive();
		bool IsCameraActive();

	public:
		void SetOrigin(std::shared_ptr<Core::ITransformable> value);
		std::shared_ptr<Core::ITransformable> GetOrigin() const { return origin; };

		void SetZoom(float value);
		float GetZoom() const { return zoom; }

	private:
		std::shared_ptr<Core::ITransformable> origin;
		float zoom;
	};

	sf::Vector2f FromWorldToCameraSpace(const sf::Vector2f& coords, const Camera* const camera);
	sf::Vector2f FromCameraToWorldSpace(const sf::Vector2f& coords, const Camera* const  camera);
	sf::Vector2f FromCameraToScreenSpace(const sf::Vector2f& coords, const Camera* const camera);
	sf::Vector2f FromScreenToCameraSpace(const sf::Vector2f& coords, const Camera* const camera);
	sf::Vector2f FromWorldToScreenSpace(const sf::Vector2f& coords, const Camera* const camera);
	sf::Vector2f FromScreenToWorldSpace(const sf::Vector2f& coords, const Camera* const camera);
}