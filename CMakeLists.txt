cmake_minimum_required(VERSION 3.16)
project(helloSDL VERSION 0.1 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set the output directory for built objects.
# This makes sure that the dynamic library goes into the build directory automatically.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

# This assumes the SDL source is available in vendored/SDL
add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)

# This assumes the SDL_image source is available in vendored/SDL_image
add_subdirectory(vendored/SDL_image EXCLUDE_FROM_ALL)

# Create your game executable target as usual
# note: the WIN32 flag is used to create a GUI application on Windows instead of console app. Ignored on linux and can be left there
add_executable(SAMPLE_MainLoopSDL WIN32 samples/mainloop.cpp)
add_executable(SAMPLE_DrawTexture WIN32 samples/drawTexture.cpp)

# build example apps
# add_executable(texturesSample WIN32 vendored/SDL/examples/renderer/06-textures/textures.c)

# Link to the actual SDL3 library.
target_link_libraries(SAMPLE_MainLoopSDL PRIVATE SDL3_image::SDL3_image SDL3::SDL3)
target_link_libraries(SAMPLE_DrawTexture PRIVATE SDL3_image::SDL3_image SDL3::SDL3)