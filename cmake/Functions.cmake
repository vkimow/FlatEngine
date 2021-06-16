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
    
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${FLAT_BIN_DIR}/${FLAT_CONFIG_STRING}/CMake")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${FLAT_BIN_DIR}/${FLAT_CONFIG_STRING}/CMake")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${FLAT_BIN_DIR}/${FLAT_CONFIG_STRING}/CMake")
endmacro()

function(set_flat_main_library)

endfunction()

function(add_flat_library)
    set(PREFIX THIS)
    set(SINGLE_VALUES LIBRARY_NAME)
    set(MULTI_VALUES SOURCES INCLUDE_DIRS LINK_LIBRARIES)

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

    #include
    target_include_directories(${THIS_LIBRARY_NAME} PRIVATE ${THIS_INCLUDE_DIRS})
    
    #link
    target_link_libraries(${THIS_LIBRARY_NAME} ${THIS_LINK_LIBRARIES})

    # alias
    string(TOLOWER ${THIS_LIBRARY_NAME} THIS_LIBRARY_LOWER_NAME)
    add_library("flat::${THIS_LIBRARY_LOWER_NAME}" ALIAS ${THIS_LIBRARY_NAME})

    # properties
    set_target_properties(${THIS_LIBRARY_NAME} PROPERTIES FOLDER FlatEngine)
    set_target_properties(${THIS_LIBRARY_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${FLAT_BIN_DIR}/${FLAT_CONFIG_STRING}/${FLAT_PROJECT_NAME}/${THIS_LIBRARY_NAME}")
    set_target_properties(${THIS_LIBRARY_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${FLAT_BIN_DIR}/${FLAT_CONFIG_STRING}/${FLAT_PROJECT_NAME}/${THIS_LIBRARY_NAME}")
    set_target_properties(${THIS_LIBRARY_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${FLAT_BIN_DIR}/${FLAT_CONFIG_STRING}/${FLAT_PROJECT_NAME}/${THIS_LIBRARY_NAME}")

    # preprocessor defenitions
    # target_compile_definitions(${THIS_LIBRARY_NAME} $<$<CONFIG:Debug>:debug> $<$<CONFIG:Release>:release>)
endfunction()


macro(set_library_dirs)
    set(PREFIX THIS)
    set(SINGLE_VALUES LIBRARY_NAME)

    # parse
    cmake_parse_arguments(${PREFIX}
                        ""
                        "${SINGLE_VALUES}"
                        ""
                        ${ARGN})
             
    if (NOT "${THIS_UNPARSED_ARGUMENTS}" STREQUAL "")
        message(FATAL_ERROR "Extra unparsed arguments when calling add_flat_library: ${THIS_UNPARSED_ARGUMENTS}")
    endif()


    # upper name
    string(TOUPPER ${THIS_LIBRARY_NAME} LIBRARY_UPPER_NAME)

    # source dir
    set(FLAT_${LIBRARY_UPPER_NAME}_SOURCE_DIR "${FLAT_SOURCE_DIR}/${FLAT_PROJECT_NAME}/${PROJECT_NAME}")
    set(FLAT_CURRENT_SOURCE_DIR ${FLAT_${LIBRARY_UPPER_NAME}_SOURCE_DIR})

    # include dir
    set(FLAT_${LIBRARY_UPPER_NAME}_INCLUDE_DIR "${FLAT_INCLUDE_DIR}/${FLAT_PROJECT_NAME}/${PROJECT_NAME}")
    set(FLAT_CURRENT_INCLUDE_DIR ${FLAT_${LIBRARY_UPPER_NAME}_INCLUDE_DIR})
endmacro()


macro(set_library_sources)
    set(PREFIX THIS)
    set(SINGLE_VALUES LIBRARY_NAME)
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

    # set
    string(TOUPPER ${THIS_LIBRARY_NAME} LIBRARY_UPPER_NAME)
    set(FLAT_${LIBRARY_UPPER_NAME}_SOURCES ${THIS_SOURCES})
    set(FLAT_CURRENT_SOURCES ${FLAT_${LIBRARY_UPPER_NAME}_SOURCES})
endmacro()


macro(set_library_public_headers)
    set(PREFIX THIS)
    set(SINGLE_VALUES LIBRARY_NAME)
    set(MULTI_VALUES PUBLIC_HEADERS)

    # parse
    cmake_parse_arguments(${PREFIX}
                        ""
                        "${SINGLE_VALUES}"
                        "${MULTI_VALUES}"
                        ${ARGN})
             
    if (NOT "${THIS_UNPARSED_ARGUMENTS}" STREQUAL "")
        message(FATAL_ERROR "Extra unparsed arguments when calling add_flat_library: ${THIS_UNPARSED_ARGUMENTS}")
    endif()

    # set
    string(TOUPPER ${THIS_LIBRARY_NAME} LIBRARY_UPPER_NAME)
    set(FLAT_${LIBRARY_UPPER_NAME}_PUBLIC_HEADERS ${THIS_PUBLIC_HEADERS})
    set(FLAT_CURRENT_PUBLIC_HEADERS ${FLAT_${LIBRARY_UPPER_NAME}_PUBLIC_HEADERS})
endmacro()