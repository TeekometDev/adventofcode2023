cmake_minimum_required(VERSION 3.27)
project(day9)

set(CMAKE_CXX_STANDARD 17)

include_directories(Libraries)
add_subdirectory(Libraries)
add_subdirectory(Google-Tests)

add_executable(day9 main.cpp)
add_executable(day9_test day9_test.cpp)
target_link_libraries(day9 fileReader calculator)
target_link_libraries(day9_test fileReader calculator)
