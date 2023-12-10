project(Google-Tests)
add_subdirectory(GTestLib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run FileReaderTest.cpp DistanceCalculatorTest.cpp LoopTest.cpp)
target_link_libraries(Google_Tests_run fileReader distanceCalculator)
target_link_libraries(Google_Tests_run gtest gtest_main)