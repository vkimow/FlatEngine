#pragma once

#include "Main/FlatEngineApi.h"
#include "Elements/Vector/Vector.h"

namespace FlatEngine::Input
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