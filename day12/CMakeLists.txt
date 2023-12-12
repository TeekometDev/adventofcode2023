cmake_minimum_required(VERSION 3.27)
project(day12)

set(CMAKE_CXX_STANDARD 17)

include_directories(Library)
add_subdirectory(Library)
add_subdirectory(Google-Tests)

add_executable(day12 main.cpp)

target_link_libraries(day12 fileReader springCalculator)
