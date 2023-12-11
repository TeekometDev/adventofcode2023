//
// Created by sebas on 11.12.2023.
//

#include <gtest/gtest.h>
#include "FileReader.h"
#include "SpaceDistanceCalculator.h"

class Task1Test : public ::testing::Test {
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

TEST_F(Task1Test, TestResult) {
    spaceGrid grid = reader->read("Google-Tests/test.txt");
    int distance = calculator->calculate(grid);
    ASSERT_EQ(distance, 374);
}

TEST_F(Task1Test, TestResultDimensions) {
    spaceGrid grid = reader->read("Google-Tests/test.txt");
    ASSERT_EQ(grid.size(), 10);
    ASSERT_EQ(grid[0].size(), 10);
}
