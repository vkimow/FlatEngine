#pragma once

#include <Core.h>
#include "Simulation\Transformable.h"
#include "Simulation\IMovable.h"
#include "Simulation\IRotatable.h"

namespace FlatEngine::Core::Modules::Display
{

	class FLAT_ENGINE_API Camera
	{

	public:
		Camera();
		Camera(std::shared_ptr<Simulation::ITransformable> origin);
		~Camera();

	public:
		void SetCameraActive();
		bool IsCameraActive();

	public:
		void SetOrigin(std::shared_ptr<Simulation::ITransformable> value);
		std::shared_ptr<Simulation::ITransformable> GetOrigin() const { return origin; };

		void SetZoom(float value);
		float GetZoom() const { return zoom; }

	private:
		std::shared_ptr<Simulation::ITransformable> origin;
		float zoom;
	};

	sf::Vector2f FromWorldToCameraSpace(const sf::Vector2f& coords, const Camera* const camera);
	sf::Vector2f FromCameraToWorldSpace(const sf::Vector2f& coords, const Camera* const  camera);
	sf::Vector2f FromCameraToScreenSpace(const sf::Vector2f& coords, const Camera* const camera);
	sf::Vector2f FromScreenToCameraSpace(const sf::Vector2f& coords, const Camera* const camera);
	sf::Vector2f FromWorldToScreenSpace(const sf::Vector2f& coords, const Camera* const camera);
	sf::Vector2f FromScreenToWorldSpace(const sf::Vector2f& coords, const Camera* const camera);
}