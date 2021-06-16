#pragma once

#ifdef FLAT_PLATFORM_WINDOWS
    #define FLAT_ENGINE_API 
#else
    #error "FlatEngine supports only Windows!"
#endif