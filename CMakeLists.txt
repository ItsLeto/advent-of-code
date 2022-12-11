cmake_minimum_required(VERSION 3.12.2)
project(advent_of_code VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(inc)

# Main application
add_executable(main
    src/advent_of_code.cpp
    src/day_01.cpp
    src/day_02.cpp
    src/day_03.cpp
    src/day_04.cpp
    src/day_05.cpp
    src/day_06.cpp
    src/day_07.cpp
    src/day_08.cpp
    src/day_09.cpp
    src/day_10.cpp
    src/day_11.cpp
    src/utils.cpp
)

add_custom_command(TARGET main
          POST_BUILD
          COMMAND ${CMAKE_COMMAND} -E make_directory ${PROJECT_BINARY_DIR}
          COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/inputs ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/inputs
)
