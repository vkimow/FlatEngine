function(add_flat_executable)
    set(PREFIX THIS)
    set(SINGLE_VALUES   NAME SOLUTION_FOLDER OUTPUT_DIR)
    set(MULTI_VALUES    SOURCES 
                        PUBLIC_INCLUDE_DIRS
                        PRIVATE_INCLUDE_DIRS
                        PUBLIC_LINK_LIBS
                        PRIVATE_LINK_LIBS
                        COMPILE_DEFS
                        DEBUG_COMPILE_DEFS
                        RELEASE_COMPILE_DEFS
                        )

    # parse
    cmake_parse_arguments(${PREFIX}
                        ""
                        "${SINGLE_VALUES}"
                        "${MULTI_VALUES}"
                        ${ARGN})
             
    if (NOT "${THIS_UNPARSED_ARGUMENTS}" STREQUAL "")
        message(FATAL_ERROR "Extra unparsed arguments: ${THIS_UNPARSED_ARGUMENTS}")
    endif()

    # create
    add_executable(${THIS_NAME} ${THIS_SOURCES})

    # set properties
    set_flat_target_properties(
        TARGET                  ${THIS_NAME}
        SOLUTION_FOLDER         ${THIS_SOLUTION_FOLDER}
        OUTPUT_DIR              ${THIS_OUTPUT_DIR}
        PUBLIC_INCLUDE_DIRS     ${THIS_PUBLIC_INCLUDE_DIRS}
        PRIVATE_INCLUDE_DIRS    ${THIS_PRIVATE_INCLUDE_DIRS}
        PUBLIC_LINK_LIBS        ${THIS_PUBLIC_LINK_LIBS}
        PRIVATE_LINK_LIBS       ${THIS_PRIVATE_LINK_LIBS}
        COMPILE_DEFS            ${THIS_COMPILE_DEFS}
        DEBUG_COMPILE_DEFS      ${THIS_DEBUG_COMPILE_DEFS}
        RELEASE_COMPILE_DEFS    ${THIS_RELEASE_COMPILE_DEFS}
    )
endfunction()

function(add_flat_library)
    set(PREFIX THIS)
    set(SINGLE_VALUES   NAME SOLUTION_FOLDER OUTPUT_DIR)
    set(MULTI_VALUES    SOURCES 
                        PUBLIC_INCLUDE_DIRS
                        PRIVATE_INCLUDE_DIRS
                        PUBLIC_LINK_LIBS
                        PRIVATE_LINK_LIBS
                        COMPILE_DEFS
                        DEBUG_COMPILE_DEFS
                        RELEASE_COMPILE_DEFS
                        )

    # parse
    cmake_parse_arguments(${PREFIX}
                        ""
                        "${SINGLE_VALUES}"
                        "${MULTI_VALUES}"
                        ${ARGN})
             
    if (NOT "${THIS_UNPARSED_ARGUMENTS}" STREQUAL "")
        message(FATAL_ERROR "Extra unparsed arguments: ${THIS_UNPARSED_ARGUMENTS}")
    endif()

    # create
    add_library(${THIS_NAME} STATIC ${THIS_SOURCES})

    # alias
    string(TOLOWER ${THIS_NAME} LOWER_NAME)
    add_library("flat::${LOWER_NAME}" ALIAS ${THIS_NAME})

    # set properties
    set_flat_target_properties(
        TARGET                  ${THIS_NAME}
        SOLUTION_FOLDER         ${THIS_SOLUTION_FOLDER}
        OUTPUT_DIR              ${THIS_OUTPUT_DIR}
        PUBLIC_INCLUDE_DIRS     ${THIS_PUBLIC_INCLUDE_DIRS}
        PRIVATE_INCLUDE_DIRS    ${THIS_PRIVATE_INCLUDE_DIRS}
        PUBLIC_LINK_LIBS        ${THIS_PUBLIC_LINK_LIBS}
        PRIVATE_LINK_LIBS       ${THIS_PRIVATE_LINK_LIBS}
        COMPILE_DEFS            ${THIS_COMPILE_DEFS}
        DEBUG_COMPILE_DEFS      ${THIS_DEBUG_COMPILE_DEFS}
        RELEASE_COMPILE_DEFS    ${THIS_RELEASE_COMPILE_DEFS}
    )
endfunction()

function(set_flat_target_properties)
    set(PREFIX THIS)
    set(SINGLE_VALUES TARGET SOLUTION_FOLDER OUTPUT_DIR)
    set(MULTI_VALUES    PUBLIC_INCLUDE_DIRS
                        PRIVATE_INCLUDE_DIRS
                        PUBLIC_LINK_LIBS
                        PRIVATE_LINK_LIBS
                        COMPILE_DEFS
                        DEBUG_COMPILE_DEFS
                        RELEASE_COMPILE_DEFS
                        )

    # parse
    cmake_parse_arguments(${PREFIX}
                        ""
                        "${SINGLE_VALUES}"
                        "${MULTI_VALUES}"
                        ${ARGN})
             
    if (NOT "${THIS_UNPARSED_ARGUMENTS}" STREQUAL "")
        message(FATAL_ERROR "Extra unparsed arguments: ${THIS_UNPARSED_ARGUMENTS}")
    endif()
    
    #include
    if(NOT "${THIS_PUBLIC_INCLUDE_DIRS}" STREQUAL "")
        target_include_directories(${THIS_TARGET} PUBLIC ${THIS_PUBLIC_INCLUDE_DIRS})
    endif()

    if(NOT "${THIS_PRIVATE_INCLUDE_DIRS}" STREQUAL "")
        target_include_directories(${THIS_TARGET} PRIVATE ${THIS_PRIVATE_INCLUDE_DIRS})
    endif()

    #link
    if(NOT "${THIS_PUBLIC_LINK_LIBS}" STREQUAL "")
        target_link_libraries(${THIS_TARGET} PUBLIC ${THIS_PUBLIC_LINK_LIBS})
    endif()

    if(NOT "${THIS_PRIVATE_LINK_LIBS}" STREQUAL "")
        target_link_libraries(${THIS_TARGET} PRIVATE ${THIS_PRIVATE_LINK_LIBS})
    endif()

    # compile defenitions
    if(NOT "${THIS_COMPILE_DEFS}" STREQUAL "")
        set_flat_target_compile_defs(TARGET ${THIS_TARGET} COMPILE_DEFS ${THIS_COMPILE_DEFS})
    endif()

    if(NOT "${THIS_DEBUG_COMPILE_DEFS}" STREQUAL "")
        set_flat_target_compile_defs(TARGET ${THIS_TARGET} CONFIG "Debug" COMPILE_DEFS ${THIS_DEBUG_COMPILE_DEFS})
    endif()

    if(NOT "${THIS_RELEASE_COMPILE_DEFS}" STREQUAL "")
        set_flat_target_compile_defs(TARGET ${THIS_TARGET} CONFIG "Release" COMPILE_DEFS ${THIS_RELEASE_COMPILE_DEFS})
    endif()

    # output dir
    if(NOT "${THIS_OUTPUT_DIR}" STREQUAL "")
        set_flat_target_output_dir(TARGET ${THIS_TARGET} OUTPUT_DIR ${THIS_OUTPUT_DIR})
    endif()

    # folder
    if(NOT "${THIS_SOLUTION_FOLDER}" STREQUAL "")
        set_target_properties(${THIS_TARGET} PROPERTIES FOLDER ${THIS_SOLUTION_FOLDER})
    endif()
endfunction()

function(set_flat_target_output_dir)
    set(PREFIX THIS)
    set(SINGLE_VALUES TARGET OUTPUT_DIR)

    # parse
    cmake_parse_arguments(${PREFIX}
                        ""
                        "${SINGLE_VALUES}"
                        ""
                        ${ARGN})
            
    if (NOT "${THIS_UNPARSED_ARGUMENTS}" STREQUAL "")
        message(FATAL_ERROR "Extra unparsed arguments: ${THIS_UNPARSED_ARGUMENTS}")
    endif()

    set_target_properties(${THIS_TARGET} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${THIS_OUTPUT_DIR})
    set_target_properties(${THIS_TARGET} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${THIS_OUTPUT_DIR})
    set_target_properties(${THIS_TARGET} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${THIS_OUTPUT_DIR})
endfunction()

function(set_flat_target_compile_defs)
    set(PREFIX THIS)
    set(SINGLE_VALUES   TARGET CONFIG)
    set(MULTI_VALUES    COMPILE_DEFS
                        )

    # parse
    cmake_parse_arguments(${PREFIX}
                        ""
                        "${SINGLE_VALUES}"
                        "${MULTI_VALUES}"
                        ${ARGN})
            
    if (NOT "${THIS_UNPARSED_ARGUMENTS}" STREQUAL "")
        message(FATAL_ERROR "Extra unparsed arguments: ${THIS_UNPARSED_ARGUMENTS}")
    endif()
      
    if(NOT "${THIS_CONFIG}" STREQUAL "")
        target_compile_definitions(${THIS_TARGET} $<$<CONFIG:${THIS_CONFIG}>:${THIS_COMPILE_DEFS}>)
    else()
        target_compile_definitions(${THIS_TARGET} ${THIS_COMPILE_DEFS})
    endif()
endfunction()

function(set_flat_target_dirs)
    set(PREFIX THIS)
    set(SINGLE_VALUES TARGET SOURCE_DIR INCLUDE_DIR OUTPUT_DIR)

    # parse
    cmake_parse_arguments(${PREFIX}
                        ""
                        "${SINGLE_VALUES}"
                        ""
                        ${ARGN})
             
    if (NOT "${THIS_UNPARSED_ARGUMENTS}" STREQUAL "")
        message(FATAL_ERROR "Extra unparsed arguments: ${THIS_UNPARSED_ARGUMENTS}")
    endif()

    # upper name
    string(TOUPPER ${THIS_TARGET} TARGET_UPPER_NAME)

    # source dir
    set(FLAT_CURRENT_SOURCE_DIR "${THIS_SOURCE_DIR}/${THIS_TARGET}" CACHE INTERNAL "")
    set_property(GLOBAL PROPERTY FLAT_${TARGET_UPPER_NAME}_SOURCE_DIR ${FLAT_CURRENT_SOURCE_DIR})

    # include dir
    set(FLAT_CURRENT_INCLUDE_DIR "${THIS_INCLUDE_DIR}/${THIS_TARGET}" CACHE INTERNAL "")
    set_property(GLOBAL PROPERTY FLAT_${TARGETUPPER_NAME}_INCLUDE_DIR ${FLAT_CURRENT_INCLUDE_DIR})

    # output dir
    # set(FLAT_CURRENT_OUTPUT_DIR "${THIS_OUTPUT_DIR}/${THIS_TARGET}" CACHE INTERNAL "")
    set(FLAT_CURRENT_OUTPUT_DIR "${FLAT_BIN_CONFIG_DIR}" CACHE INTERNAL "")
    set_property(GLOBAL PROPERTY FLAT_${TARGET_UPPER_NAME}_OUTPUT_DIR ${FLAT_CURRENT_INCLUDE_DIR})

    # auto sources
    file(GLOB_RECURSE FLAT_CURRENT_AUTO_SOURCES ${FLAT_CURRENT_SOURCE_DIR}/*.cpp ${FLAT_CURRENT_SOURCE_DIR}/*.h)
    set(FLAT_CURRENT_AUTO_SOURCES ${FLAT_CURRENT_AUTO_SOURCES} CACHE INTERNAL "")
    set_property(GLOBAL PROPERTY FLAT_${TARGET_UPPER_NAME}_AUTO_SOURCES ${FLAT_CURRENT_AUTO_SOURCES})

    # auto public headers
    file(GLOB_RECURSE FLAT_CURRENT_AUTO_PUBLIC_HEADERS ${FLAT_CURRENT_INCLUDE_DIR}/*.h)
    set(FLAT_CURRENT_AUTO_PUBLIC_HEADERS ${FLAT_CURRENT_AUTO_PUBLIC_HEADERS} CACHE INTERNAL "")
    set_property(GLOBAL PROPERTY FLAT_${TARGET_UPPER_NAME}_AUTO_PUBLIC_HEADERS ${FLAT_CURRENT_AUTO_PUBLIC_HEADERS})
endfunction()

function(set_flat_target_files)
    set(PREFIX THIS)
    set(SINGLE_VALUES TARGET VARIABLE FILES_DIR)
    set(MULTI_VALUES FILES)

    # parse
    cmake_parse_arguments(${PREFIX}
                        ""
                        "${SINGLE_VALUES}"
                        "${MULTI_VALUES}"
                        ${ARGN})
             
    if (NOT "${THIS_UNPARSED_ARGUMENTS}" STREQUAL "")
        message(FATAL_ERROR "Extra unparsed arguments: ${THIS_UNPARSED_ARGUMENTS}")
    endif()

    # set
    string(TOUPPER ${THIS_TARGET} TARGET_UPPER_NAME)
    set(FLAT_CURRENT_${THIS_VARIABLE} ${THIS_FILES} CACHE INTERNAL "")
    set_property(GLOBAL PROPERTY FLAT_${TARGET_UPPER_NAME}_${THIS_VARIABLE} ${FLAT_CURRENT_${THIS_VARIABLE}})

    generate_flat_ide_folders(
        FILES_DIR ${THIS_FILES_DIR} 
        FILES ${FLAT_CURRENT_${THIS_VARIABLE}}
        )
endfunction()


macro(set_flat_subsolution)
    set(PREFIX THIS)
    set(SINGLE_VALUES NAME PATH)

    # parse
    cmake_parse_arguments(${PREFIX}
                        ""
                        "${SINGLE_VALUES}"
                        ""
                        ${ARGN})
            
    if (NOT "${THIS_UNPARSED_ARGUMENTS}" STREQUAL "")
        message(FATAL_ERROR "Extra unparsed arguments: ${THIS_UNPARSED_ARGUMENTS}")
    endif()

    # set subsolution
    set(FLAT_CURRENT_SUBSOLUTION_NAME ${THIS_NAME} CACHE INTERNAL "")
    string(TOUPPER ${THIS_NAME} UPPER_NAME)

    # set subsolution dir
    if(NOT "${FLAT_CURRENT_SUBSOLUTION}" STREQUAL "")
        set(FLAT_CURRENT_SUBSOLUTION "${FLAT_CURRENT_SUBSOLUTION}/${THIS_NAME}")
    else()
        set(FLAT_CURRENT_SUBSOLUTION "${THIS_NAME}")
    endif()

    # set subsolution dirs
    set(FLAT_CURRENT_SUBSOLUTION_SOURCE_DIR "${FLAT_SOURCE_DIR}/${FLAT_CURRENT_SUBSOLUTION}" CACHE INTERNAL "")
    set(FLAT_CURRENT_SUBSOLUTION_INCLUDE_DIR "${FLAT_INCLUDE_DIR}/${FLAT_CURRENT_SUBSOLUTION}" CACHE INTERNAL "")
    set(FLAT_CURRENT_SUBSOLUTION_OUTPUT_DIR "${FLAT_BIN_CONFIG_DIR}/${FLAT_CURRENT_SUBSOLUTION}" CACHE INTERNAL "")

    # set global dirs
    set_property(GLOBAL PROPERTY FLAT_${UPPER_NAME}_SUBSOLUTION_SOURCE_DIR ${FLAT_CURRENT_SUBSOLUTION_SOURCE_DIR})
    set_property(GLOBAL PROPERTY FLAT_${UPPER_NAME}_SUBSOLUTION_INCLUDE_DIR ${FLAT_CURRENT_SUBSOLUTION_INCLUDE_DIR})
    set_property(GLOBAL PROPERTY FLAT_${UPPER_NAME}_SUBSOLUTION_OUTPUT_DIR ${FLAT_CURRENT_SUBSOLUTION_OUTPUT_DIR})
endmacro()

function(generate_flat_ide_folders)
    set(PREFIX THIS)
    set(SINGLE_VALUES FILES_DIR)
    set(MULTI_VALUES FILES)

    # parse
    cmake_parse_arguments(${PREFIX}
                        ""
                        "${SINGLE_VALUES}"
                        "${MULTI_VALUES}"
                        ${ARGN})

    if (NOT "${THIS_UNPARSED_ARGUMENTS}" STREQUAL "")
        message(FATAL_ERROR "Extra unparsed arguments: ${THIS_UNPARSED_ARGUMENTS}")
    endif()
    
    foreach(FILE IN ITEMS ${THIS_FILES})
        get_filename_component(FILE_PATH "${FILE}" REALPATH)
        get_filename_component(FILE_PATH "${FILE_PATH}" PATH)
        file(RELATIVE_PATH FILE_PATH "${THIS_FILES_DIR}" "${FILE_PATH}")
        
        string(REPLACE "/" "\\" FILE_PATH "${FILE_PATH}")
        string(REPLACE "..\\" "" FILE_PATH "${FILE_PATH}")

        source_group("${FILE_PATH}" FILES "${FILE}")
    endforeach()
endfunction()