macro(define_dirs)
    set(FLAT_ROOT_DIR       "${CMAKE_SOURCE_DIR}")
    set(FLAT_INCLUDE_DIR    "${FLAT_ROOT_DIR}/include")
    set(FLAT_SOURCE_DIR     "${FLAT_ROOT_DIR}/src")
    set(FLAT_VENDOR_DIR     "${FLAT_ROOT_DIR}/vendor")
    set(FLAT_PROJECT_DIR    "${FLAT_ROOT_DIR}/project")
    set(FLAT_BIN_DIR        "${FLAT_ROOT_DIR}/bin")
endmacro()

macro(define_global_properties)
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

    set_property(GLOBAL PROPERTY USE_FOLDERS ON)
    set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMake")
    
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${FLAT_BIN_DIR}/$<$<CONFIG:Debug>:debug>$<$<CONFIG:Release>:release>/CMake")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${FLAT_BIN_DIR}/$<$<CONFIG:Debug>:debug>$<$<CONFIG:Release>:release>/CMake")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${FLAT_BIN_DIR}/$<$<CONFIG:Debug>:debug>$<$<CONFIG:Release>:release>/CMake")
endmacro()

function(set_flat_main_library)

endfunction()

function(add_flat_library)
    set(PREFIX THIS)
    set(SINGLE_VALUES LIBRARY_NAME INCLUDE_DIR)
    set(MULTI_VALUES SOURCES)

    # parse
    cmake_parse_arguments(${PREFIX}
                        ""
                        "${SINGLE_VALUES}"
                        "${MULTI_VALUES}"
                        ${ARGN})
             
    if (NOT "${THIS_UNPARSED_ARGUMENTS}" STREQUAL "")
        message(FATAL_ERROR "Extra unparsed arguments when calling add_flat_library: ${THIS_UNPARSED_ARGUMENTS}")
    endif()

    # create
    add_library(${THIS_LIBRARY_NAME} STATIC ${THIS_SOURCES})
    include("SetupCONFIGurations")
    target_include_directories(${THIS_LIBRARY_NAME} PRIVATE ${THIS_INCLUDE_DIR})  

    # alias
    string(TOLOWER ${THIS_LIBRARY_NAME} THIS_LIBRARY_LOWER_NAME)
    add_library("flat::${THIS_LIBRARY_LOWER_NAME}" ALIAS ${THIS_LIBRARY_NAME})

    # properties
    set_target_properties(${THIS_LIBRARY_NAME} PROPERTIES FOLDER FlatEngine)
    set_target_properties(${THIS_LIBRARY_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${FLAT_BIN_DIR}/$<$<CONFIG:Debug>:debug>$<$<CONFIG:Release>:release>/${FLAT_PROJECT_NAME}/${THIS_LIBRARY_NAME}")
    set_target_properties(${THIS_LIBRARY_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${FLAT_BIN_DIR}/$<$<CONFIG:Debug>:debug>$<$<CONFIG:Release>:release>/${FLAT_PROJECT_NAME}/${THIS_LIBRARY_NAME}")
    set_target_properties(${THIS_LIBRARY_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${FLAT_BIN_DIR}/$<$<CONFIG:Debug>:debug>$<$<CONFIG:Release>:release>/${FLAT_PROJECT_NAME}/${THIS_LIBRARY_NAME}")
    #target_compile_definitions(${THIS_LIBRARY_NAME} $<$<CONFIG:Debug>:debug> $<$<CONFIG:Release>:release>)    
endfunction()