# use sfml prepared cmake file for libs
set(SFML_DIR ${FLAT_VENDOR_DIR}/SFML)
set(_IMPORT_PREFIX ${SFML_DIR})
include(${SFML_DIR}/lib/cmake/SFML/SFMLSharedTargets.cmake)

# add alias for sfml libraries  
add_library(sfml::audio     ALIAS   sfml-audio)     
add_library(sfml::graphics  ALIAS   sfml-graphics)
add_library(sfml::main      ALIAS   sfml-main)      
add_library(sfml::network   ALIAS   sfml-network)   
add_library(sfml::system    ALIAS   sfml-system)   
add_library(sfml::window    ALIAS   sfml-window)    

