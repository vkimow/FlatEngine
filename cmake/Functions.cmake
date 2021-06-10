function(define_build_type)
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        set(IS_DEBUG TRUE)
        set(BUILD_TYPE_DIR "debug")
    elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
        set(IS_RELEASE TRUE)
        set(BUILD_TYPE_DIR "release")
    else()
        message(FATAL_ERROR "You are using unsupported build type! ${CMAKE_BUILD_TYPE}")
    endif()


    set(BIN_DIR ${CMAKE_SOURCE_DIR}/bin/${BUILD_TYPE_DIR})
endfunction()

function(add_flat_library)
    set(PREFIX THIS)
    set(SINGLE_VALUES LIBRARY_NAME)
    set(MULTI_VALUES SOURCES PUBLIC_HEADERS)

    # parse the arguments
    cmake_parse_arguments(${PREFIX}
                        ""
                        "${SINGLE_VALUES}"
                        "${MULTI_VALUES}"
                        ${ARGN})
             
    if (NOT "${THIS_UNPARSED_ARGUMENTS}" STREQUAL "")
        message(FATAL_ERROR "Extra unparsed arguments when calling sfml_add_library: ${THIS_UNPARSED_ARGUMENTS}")
    endif()

    add_library(${THIS_LIBRARY_NAME} STATIC ${THIS_SOURCES})
    target_include_directories(${THIS_LIBRARY_NAME} PUBLIC ${THIS_PUBLIC_HEADERS})   

    set_target_properties(${THIS_LIBRARY_NAME} PROPERTIES FOLDER FlatEngine)
    set_target_properties(${THIS_LIBRARY_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR}
										        VERSION ${PROJECT_VERSION}
                        )
endfunction()

function(clean_temporary_cmake_files ${target})

    set(cmake_generated ${CMAKE_BINARY_DIR}/CMakeCache.txt
                        ${CMAKE_BINARY_DIR}/cmake_install.cmake
                        ${CMAKE_BINARY_DIR}/Makefile
                        ${CMAKE_BINARY_DIR}/CMakeFiles
    )

    foreach(file ${cmake_generated})

        if (EXISTS ${file})
            file(REMOVE_RECURSE ${file})
        endif()

    endforeach(file)   
endfunction()

function(add_flat_library_2)
    set(prefix THIS)
    set(SINGLE_VALUES TARGET)
    set(MULTI_VALUES SOURCES RES)

    include(CMakeParseArguments)
    cmake_parse_arguments(${prefix}
                     "${flags}"
                     "${SINGLE_VALUES}"
                     "${MULTI_VALUES}"
                    ${ARGN})
    message(" THIS_IS_ASCII: ${THIS_IS_ASCII}")
    message(" THIS_IS_UNICODE: ${THIS_IS_UNICODE}")
    message(" THIS_TARGET: ${THIS_TARGET}")
    message(" THIS_SOURCES: ${THIS_SOURCES}")
    message(" THIS_RES: ${THIS_RES}")
    message(" THIS_UNPARSED_ARGUMENTS: ${THIS_UNPARSED_ARGUMENTS}")
endfunction()