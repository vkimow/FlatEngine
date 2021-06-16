#include "FrameSpeed.h"
#include <stdexcept>

namespace FlatEngine::Core::Modules::Display
{
	FrameSpeed::FrameSpeed() noexcept
		: FrameSpeed((size_t)1)
	{}

	FrameSpeed::FrameSpeed(size_t framerate) noexcept
		:
		framesPerSecond(framerate),
		frameTime(1.0f / framerate)
	{}

	FrameSpeed::FrameSpeed(float framerate)
	{
		SetFramerate(framerate);
	}

	void FrameSpeed::SetFramerate(size_t value)
	{
		framesPerSecond = value;
		frameTime = 1.0f / value;
	}

	void FrameSpeed::SetFramerate(float value)
	{
		if (value <= 0)
			throw std::invalid_argument("Framerate must be positive!");

		framesPerSecond = value;
		frameTime = 1.0f / value;
	}
	void FrameSpeed::SetFrameTime(float value)
	{
		if (value <= 0)
			throw std::invalid_argument("Framerate must be positive!");

		frameTime = value;
		framesPerSecond = 1.0f / value;
	}
}