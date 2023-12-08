cmake_minimum_required(VERSION 3.26)
project(day8)

set(CMAKE_CXX_STANDARD 17)

add_executable(day8 main.cpp)
add_executable(day8_test test.cpp)

add_library(FileReader FileReader.cpp FileReader.h)
add_library(Pathfinder Pathfinder.cpp Pathfinder.h)

target_link_libraries(day8 FileReader Pathfinder)
target_link_libraries(day8_test FileReader Pathfinder)
target_link_libraries(Pathfinder FileReader)
