project(Google-Tests)
add_subdirectory(GTestLib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run Task1Test.cpp Task2Test.cpp)
target_link_libraries(Google_Tests_run fileReader distanceCalculator)
target_link_libraries(Google_Tests_run gtest gtest_main)