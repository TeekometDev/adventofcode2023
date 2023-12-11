//
// Created by sebas on 11.12.2023.
//

#include <gtest/gtest.h>
#include "FileReader.h"
#include "SpaceDistanceCalculator.h"

class Task2Test : public ::testing::Test {
protected:
    void SetUp() override {
        reader = new FileReader();
        calculator = new SpaceDistanceCalculator();
    }

    void TearDown() override {
        delete reader;
        delete calculator;
    }

    FileReader *reader;
    SpaceDistanceCalculator *calculator;
};

TEST_F(Task2Test, TestFactor10) {
    spaceGrid grid = reader->read("Google-Tests/test.txt");
    unsigned long long distance = calculator->expandedUniverseCalculation(grid, 10);
    ASSERT_EQ(distance, 1030);
}

TEST_F(Task2Test, TestFactor100) {
    spaceGrid grid = reader->read("Google-Tests/test.txt");
    unsigned long long distance = calculator->expandedUniverseCalculation(grid, 100);
    ASSERT_EQ(distance, 8410);
}