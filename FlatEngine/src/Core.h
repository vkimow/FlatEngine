#pragma once

#ifdef FLAT_ENGINE_PLATFORM_WINDOWS

#ifdef FLAT_ENGINE_BUILD_DLL
#define FLAT_ENGINE_API __declspec(dllexport)
#else 
#define FLAT_ENGINE_API __declspec(dllimport)
#endif

#else
#error Flat Engine only supports Windows!
#endif