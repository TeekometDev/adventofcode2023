project(Google-Tests)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run ExtrapolationCalculatorTest.cpp)
target_link_libraries(Google_Tests_run calculator)
target_link_libraries(Google_Tests_run gtest gtest_main)