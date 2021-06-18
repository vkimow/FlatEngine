#pragma once

#include "FlatEngineApi.h"
#include "Vector.h"

namespace FlatEngine::Core::Modules::Input
{
	class Pressable;
	class Delta;

	class FLAT_ENGINE_API VectorDelta : public Vector
	{
	public:
		VectorDelta() = delete;
		VectorDelta(const std::shared_ptr<Delta>& x,
					const std::shared_ptr<Delta>& y);

		~VectorDelta() {};

	protected:
		virtual sf::Vector2f GetVectorInput(const sf::Event& event) override final;

	private:
		std::shared_ptr<Delta> x;
		std::shared_ptr<Delta> y;
	};
}