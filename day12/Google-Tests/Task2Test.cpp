//
// Created by sebas on 12.12.2023.
//

#include "gtest/gtest.h"
#include "SpringCalculator.h"
#include "FileReader.h"

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
    informationLines input = reader->read("Google-Tests/test.txt");
    ASSERT_EQ(calculator->calculateTask2(input), 525152);
}
