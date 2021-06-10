cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

project(FlatEngine CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include("cmake/Functions.cmake")


if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

define_build_type()

set(FLAT_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(FLAT_SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")


set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMake")

add_subdirectory(src/FlatEngine FlatEngine)
