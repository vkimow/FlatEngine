workspace "FlatEngine"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "FlatEngine"
    location "FlatEngine"
    king "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%prj.name")
    objdir ("bin_int/" .. outputdir .. "/%prj.name")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    FLAT_ENGINE_PLATFORM_WINDOWS;FLAT_ENGINE_BUILD_DLL; _WINDLL;