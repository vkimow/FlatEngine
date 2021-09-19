include(FetchContent)

FetchContent_Declare(
  sfmllibrary
  GIT_REPOSITORY https://github.com/SFML/SFML
  GIT_TAG        3b1ff125b06e010ec1acf1bbec113adc0c8c57cd # 2.5.1
)

FetchContent_MakeAvailable(sfmllibrary)

# add alias for sfml libraries  
add_library(sfml::audio     ALIAS   sfml-audio)     
add_library(sfml::graphics  ALIAS   sfml-graphics)
add_library(sfml::main      ALIAS   sfml-main)      
add_library(sfml::network   ALIAS   sfml-network)   
add_library(sfml::system    ALIAS   sfml-system)   
add_library(sfml::window    ALIAS   sfml-window)

