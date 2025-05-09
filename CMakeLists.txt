cmake_minimum_required(VERSION 3.10)
project(SortingVisualizer LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

set(SOURCES 
    src/main.cpp 
    src/App/App.cpp
    src/Visualizer/SVisu.cpp
    Theme/Colors.cpp
)

add_executable(SortingVisualizer ${SOURCES})
target_link_libraries(SortingVisualizer PRIVATE SFML::Graphics)
