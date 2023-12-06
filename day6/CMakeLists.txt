cmake_minimum_required(VERSION 3.26)
project(day6)

set(CMAKE_CXX_STANDARD 17)

add_library(gatheringData gatheringData.cpp gatheringData.h)
add_library(winningCalc Task1_WinningCalc.cpp Task1_WinningCalc.h)
add_library(winningCalc2 Task2_Calculations.cpp Task2_Calculations.h)
target_link_libraries(winningCalc PUBLIC gatheringData)

add_executable(test testing.cpp)
add_executable(real_calculation real_calculation.cpp)
target_link_libraries(test gatheringData winningCalc winningCalc2)
target_link_libraries(real_calculation gatheringData winningCalc winningCalc2)