cmake_minimum_required(VERSION 3.27)
project(day15)

set(CMAKE_CXX_STANDARD 17)

include_directories(Library)
add_subdirectory(Library)
add_subdirectory(Google-Tests)

add_executable(day15 main.cpp)

target_link_libraries(day15 fileReader hashAlgorithm hashMap)
