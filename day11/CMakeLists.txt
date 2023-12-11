cmake_minimum_required(VERSION 3.27)
project(day11)

set(CMAKE_CXX_STANDARD 17)

include_directories(Libraries)
add_subdirectory(Libraries)
add_subdirectory(Google-Tests)

add_executable(day11 main.cpp)

target_link_libraries(day11 fileReader distanceCalculator)