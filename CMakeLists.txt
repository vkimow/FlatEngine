cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

# vendors
add_subdirectory(vendor/SFML Vendor/SFML)

# project
project(FlatEngine CXX)
set(FLAT_PROJECT_NAME ${PROJECT_NAME})

# includes
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include("Functions")
include("SetupConfigurations")

# defines
define_dirs()
define_global_properties()

# vendors include dirs
set(SFML_INCLUDE_DIR "${FLAT_VENDOR_DIR}/SFML/include")

add_subdirectory(src/FlatEngine FlatEngine)
add_subdirectory(src/Sandbox Sandbox)
