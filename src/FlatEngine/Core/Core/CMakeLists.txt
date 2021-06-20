cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

project(Core CXX)

set_flat_target_dirs(
    TARGET ${PROJECT_NAME}
    SOURCE_DIR ${FLAT_CURRENT_SUBSOLUTION_SOURCE_DIR}
    INCLUDE_DIR ${FLAT_CURRENT_SUBSOLUTION_INCLUDE_DIR}
    OUTPUT_DIR ${FLAT_CURRENT_SUBSOLUTION_OUTPUT_DIR}
    )

set_flat_target_files(
    VARIABLE SOURCES
    TARGET ${PROJECT_NAME}
    FILES_DIR ${FLAT_CURRENT_SOURCE_DIR}
    FILES ${FLAT_CURRENT_AUTO_SOURCES}
    )

set_flat_target_files(
    VARIABLE PUBLIC_HEADERS
    TARGET ${PROJECT_NAME}
    FILES_DIR ${FLAT_CURRENT_INCLUDE_DIR}
    FILES ${FLAT_CURRENT_AUTO_PUBLIC_HEADERS}
    )

add_flat_library(   
    NAME ${PROJECT_NAME}
    SOLUTION_FOLDER ${FLAT_CURRENT_SUBSOLUTION}
    OUTPUT_DIR ${FLAT_CURRENT_OUTPUT_DIR}
    SOURCES ${FLAT_CURRENT_SOURCES} ${FLAT_CURRENT_PUBLIC_HEADERS}
    PUBLIC_LINK_LIBS    SFML
                        flat::tools
                        flat::time
                        flat::update
                        flat::input
                        flat::display
                        flat::transform
                        #flat::audio
                        #flat::collision
    )