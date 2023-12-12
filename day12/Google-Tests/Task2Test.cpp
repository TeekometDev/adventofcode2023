//
// Created by sebas on 12.12.2023.
//

#include "gtest/gtest.h"
#include "SpringCalculator.h"
#include "FileReader.h"
#include <chrono>

class Day12Task2Fixture : public ::testing::Test {
protected:
    virtual void SetUp() {
        calculator = new SpringCalculator();
        reader = new FileReader();
    }

    virtual void TearDown() {
        delete calculator;
        delete reader;
    }

    SpringCalculator *calculator;
    FileReader *reader;
};

TEST_F(Day12Task2Fixture, Task2Test1) {
    informationLines input = reader->read("Google-Tests/test.txt");
    ASSERT_EQ(calculator->calculateMethod2(input), 21);
}

TEST_F(Day12Task2Fixture, Task2Test2) {
    auto start = std::chrono::high_resolution_clock::now();
    informationLines input = reader->read("Google-Tests/test.txt");
    ASSERT_EQ(calculator->calculateTask2(input), 525152);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
}

TEST_F(Day12Task2Fixture, Task2Test2Multithreading) {
    auto start = std::chrono::high_resolution_clock::now();
    informationLines input = reader->read("Google-Tests/test.txt");
    ASSERT_EQ(calculator->calculateTask2Multithreading(input), 525152);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
}
