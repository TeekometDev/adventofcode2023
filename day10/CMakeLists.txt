cmake_minimum_required(VERSION 3.27)
project(day10)

set(CMAKE_CXX_STANDARD 17)

include_directories(Libraries)
add_subdirectory(Libraries)
add_subdirectory(Google-Tests)

add_executable(day10 main.cpp)
target_link_libraries(day10 fileReader distanceCalculator)
