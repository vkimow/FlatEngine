cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# includes
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include("SetupConfigurations")
include("SetupGlobalProperties")
include("SetupGlobalDirectories")
include("SetupVendorLibs")
include("Functions")

# project
project(FlatEngine CXX)
set(FLAT_PROJECT_NAME ${PROJECT_NAME})

# vendors include dirs
add_subdirectory(src/FlatEngine FlatEngine)