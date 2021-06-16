#pragma once

#include <Core.h>

namespace FlatEngine::Core::Modules::Display
{
	class FLAT_ENGINE_API FrameSpeed
	{
	public:
		FrameSpeed() noexcept;
		explicit FrameSpeed(size_t framerate) noexcept;
		explicit FrameSpeed(float framerate);

	public:
		void SetFramerate(size_t value);
		void SetFramerate(float value);
		void SetFrameTime(float value);

		float GetFramerate() const { return framesPerSecond; }
		float GetFrameTime() const { return frameTime; }

	private:
		float framesPerSecond;
		float frameTime;
	};
}