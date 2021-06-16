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
    set(SINGLE_VALUES LIBRARY_NAME SOLUTION_FOLDER)
    set(MULTI_VALUES SOURCES INCLUDE_DIRS LINK_LIBS)

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
    target_link_libraries(${THIS_LIBRARY_NAME} ${THIS_LINK_LIBS})

    # alias
    string(TOLOWER ${THIS_LIBRARY_NAME} THIS_LIBRARY_LOWER_NAME)
    add_library("flat::${THIS_LIBRARY_LOWER_NAME}" ALIAS ${THIS_LIBRARY_NAME})

    # folder
    if(THIS_SOLUTION_FOLDER)
        set_target_properties(${THIS_LIBRARY_NAME} PROPERTIES FOLDER FlatEngine/${THIS_SOLUTION_FOLDER})
    else()
        set_target_properties(${THIS_LIBRARY_NAME} PROPERTIES FOLDER FlatEngine)
    endif()

    # properties
    set_target_properties(${THIS_LIBRARY_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${FLAT_BIN_DIR}/${FLAT_CONFIG_STRING}/${FLAT_PROJECT_NAME}/${THIS_LIBRARY_NAME}")
    set_target_properties(${THIS_LIBRARY_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${FLAT_BIN_DIR}/${FLAT_CONFIG_STRING}/${FLAT_PROJECT_NAME}/${THIS_LIBRARY_NAME}")
    set_target_properties(${THIS_LIBRARY_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${FLAT_BIN_DIR}/${FLAT_CONFIG_STRING}/${FLAT_PROJECT_NAME}/${THIS_LIBRARY_NAME}")

    # preprocessor defenitions
    # target_compile_definitions(${THIS_LIBRARY_NAME} $<$<CONFIG:Debug>:debug> $<$<CONFIG:Release>:release>)
endfunction()

macro(set_flat_library_dirs)
    set(PREFIX THIS)
    set(SINGLE_VALUES LIBRARY_NAME INTERMEDIATE_FOLDERS)

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
    set(FLAT_${LIBRARY_UPPER_NAME}_SOURCE_DIR "${FLAT_SOURCE_DIR}/${FLAT_PROJECT_NAME}/${THIS_INTERMEDIATE_FOLDERS}/${THIS_LIBRARY_NAME}")
    set(FLAT_CURRENT_SOURCE_DIR ${FLAT_${LIBRARY_UPPER_NAME}_SOURCE_DIR})

    # include dir
    set(FLAT_${LIBRARY_UPPER_NAME}_INCLUDE_DIR "${FLAT_INCLUDE_DIR}/${FLAT_PROJECT_NAME}/${THIS_INTERMEDIATE_FOLDERS}/${THIS_LIBRARY_NAME}")
    set(FLAT_CURRENT_INCLUDE_DIR ${FLAT_${LIBRARY_UPPER_NAME}_INCLUDE_DIR})

    # auto sources
    file(GLOB_RECURSE FLAT_${LIBRARY_UPPER_NAME}_AUTO_SOURCES ${FLAT_CURRENT_SOURCE_DIR}/*.cpp ${FLAT_CURRENT_SOURCE_DIR}/*.h)
    set(FLAT_CURRENT_AUTO_SOURCES ${FLAT_${LIBRARY_UPPER_NAME}_AUTO_SOURCES})

    # auto public headers
    file(GLOB_RECURSE FLAT_${LIBRARY_UPPER_NAME}_AUTO_PUBLIC_HEADERS ${FLAT_CURRENT_INCLUDE_DIR}/*.h)
    set(FLAT_CURRENT_AUTO_PUBLIC_HEADERS ${FLAT_${LIBRARY_UPPER_NAME}_AUTO_PUBLIC_HEADERS})
endmacro()


macro(set_flat_library_files)
    set(PREFIX THIS)
    set(SINGLE_VALUES LIBRARY_NAME VARIABLE_NAME FILES_DIR)
    set(MULTI_VALUES FILES)

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
    set(FLAT_${LIBRARY_UPPER_NAME}_${THIS_VARIABLE_NAME} ${THIS_FILES})
    set(FLAT_CURRENT_${THIS_VARIABLE_NAME} ${FLAT_${LIBRARY_UPPER_NAME}_${THIS_VARIABLE_NAME}})

    
    generate_ide_folders(
        FILES_DIR ${THIS_FILES_DIR} 
        FILES ${FLAT_CURRENT_${THIS_VARIABLE_NAME}}
        )
endmacro()

function(generate_ide_folders)
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
        message(FATAL_ERROR "Extra unparsed arguments when calling add_flat_library: ${THIS_UNPARSED_ARGUMENTS}")
    endif()
    
    foreach(FILE IN ITEMS ${THIS_FILES})
        get_filename_component(FILE_PATH "${FILE}" REALPATH)
        get_filename_component(FILE_PATH "${FILE_PATH}" PATH)
        file(RELATIVE_PATH FILE_PATH "${THIS_FILES_DIR}" "${FILE_PATH}")
        
        string(REPLACE "/" "\\" FILE_PATH "${FILE_PATH}")
        string(REPLACE "..\\" "" FILE_PATH "${FILE_PATH}")

        source_group("${FILE_PATH}" FILES "${FILE}")
    endforeach()

endfunction(generate_ide_folders)