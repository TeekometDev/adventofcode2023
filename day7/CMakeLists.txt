cmake_minimum_required(VERSION 3.26)
project(day7)

set(CMAKE_CXX_STANDARD 17)

add_library(fileReader fileReader.cpp fileReader.h)
add_library(gameEvaluator GameEvaluator.cpp GameEvaluator.h)
add_executable(day7 main.cpp)
add_executable(day7_test test.cpp)
target_link_libraries(gameEvaluator fileReader)
target_link_libraries(day7 fileReader gameEvaluator)
target_link_libraries(day7_test fileReader gameEvaluator)
