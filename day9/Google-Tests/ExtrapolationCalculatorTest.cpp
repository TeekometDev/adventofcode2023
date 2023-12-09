//
// Created by sebas on 09.12.2023.
//

#include "ExtrapolationCalculator.h"
#include "gtest/gtest.h"
#include <iostream>

class ExtrapolationCalculatorFixture : public ::testing::Test {
protected:
    ExtrapolationCalculator* extrapolationCalculator;
    virtual void SetUp() {
        extrapolationCalculator = new ExtrapolationCalculator();
        matrix = new matrixOfWork();
        calculationLine line;
        calculatedLines lines;
        line.push_back(0);
        line.push_back(3);
        line.push_back(6);
        line.push_back(9);
        line.push_back(12);
        line.push_back(15);
        lines.push_back(line);
        matrix->push_back(lines);
        line.clear();
        lines.clear();
        line.push_back(1);
        line.push_back(3);
        line.push_back(6);
        line.push_back(10);
        line.push_back(15);
        line.push_back(21);
        lines.push_back(line);
        matrix->push_back(lines);
        line.clear();
        lines.clear();
        line.push_back(10);
        line.push_back(13);
        line.push_back(16);
        line.push_back(21);
        line.push_back(30);
        line.push_back(45);
        lines.push_back(line);
        matrix->push_back(lines);
    }
    matrixOfWork *matrix;
};

TEST_F(ExtrapolationCalculatorFixture, calculate) {
    ExtrapolationCalculator extrapolationCalculator;
    int result = extrapolationCalculator.calculate(*matrix);
    ASSERT_EQ(result, 114);
}

TEST_F(ExtrapolationCalculatorFixture, backwardsValue) {
    ExtrapolationCalculator extrapolationCalculator;
    int result = extrapolationCalculator.calculate(*matrix);
    ASSERT_EQ(result, 114);
    result = extrapolationCalculator.getBackwardValue();
    ASSERT_EQ(result, 2);
}
