cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

# vendors
add_subdirectory(vendor/SFML Vendor/SFML)
set(SFML_INCLUDE_DIR "${FLAT_VENDOR_DIR}/SFML/include")

# includes
include("cmake/Functions.cmake")

# project
project(FlatEngine CXX)
set(FLAT_PROJECT_NAME ${PROJECT_NAME})

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

define_build_type()
define_dirs()
define_global_properties()

add_subdirectory(src/FlatEngine FlatEngine)
add_subdirectory(src/Sandbox Sandbox)
