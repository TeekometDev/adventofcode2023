//
// Created by sebas on 10.12.2023.
//

#include "DistanceCalculator.h"
#include "gtest/gtest.h"
#include <iostream>

class DistanceCalculatorFixture : public ::testing::Test {
protected:
    virtual void SetUp() {
        setUpEasyDirections();
        setUpComplexDirections();
    }
    virtual void TearDown() {
        delete distanceCalculator;
        // The directions are removed by deconstructor of distanceCalculator
        // delete easyDirections;
        // delete complexDirections;
    }
    directionMatrix *easyDirections;
    directionMatrix *complexDirections;
    DistanceCalculator *distanceCalculator;
private:
    void setUpEasyDirections() {
        easyDirections = new directionMatrix;
        directionRow row;
        for (int i = 0; i< 5; i++) {
            row.push_back(Direction::GROUND);
        }
        easyDirections->push_back(row);
        row.clear();
        row.push_back(Direction::GROUND);
        row.push_back(Direction::START);
        row.push_back(Direction::HORIZONTAL);
        row.push_back(Direction::SOUTH_WEST);
        row.push_back(Direction::GROUND);
        easyDirections->push_back(row);
        row.clear();
        row.push_back(Direction::GROUND);
        row.push_back(Direction::VERTICAL);
        row.push_back(Direction::GROUND);
        row.push_back(Direction::VERTICAL);
        row.push_back(Direction::GROUND);
        easyDirections->push_back(row);
        row.clear();
        row.push_back(Direction::GROUND);
        row.push_back(Direction::NORTH_EAST);
        row.push_back(Direction::HORIZONTAL);
        row.push_back(Direction::NORTH_WEST);
        row.push_back(Direction::GROUND);
        easyDirections->push_back(row);
        row.clear();
        for (int i = 0; i< 5; i++) {
            row.push_back(Direction::GROUND);
        }
        easyDirections->push_back(row);
    }
    void setUpComplexDirections() {
        complexDirections = new directionMatrix;
        directionRow row;
        row.push_back(Direction::GROUND);
        row.push_back(Direction::GROUND);
        row.push_back(Direction::SOUTH_EAST);
        row.push_back(Direction::SOUTH_WEST);
        row.push_back(Direction::GROUND);
        complexDirections->push_back(row);
        row.clear();
        row.push_back(Direction::GROUND);
        row.push_back(Direction::SOUTH_EAST);
        row.push_back(Direction::NORTH_WEST);
        row.push_back(Direction::VERTICAL);
        row.push_back(Direction::GROUND);
        complexDirections->push_back(row);
        row.clear();
        row.push_back(Direction::START);
        row.push_back(Direction::NORTH_WEST);
        row.push_back(Direction::GROUND);
        row.push_back(Direction::NORTH_EAST);
        row.push_back(Direction::SOUTH_WEST);
        complexDirections->push_back(row);
        row.clear();
        row.push_back(Direction::VERTICAL);
        row.push_back(Direction::SOUTH_EAST);
        row.push_back(Direction::HORIZONTAL);
        row.push_back(Direction::HORIZONTAL);
        row.push_back(Direction::NORTH_WEST);
        complexDirections->push_back(row);
        row.clear();
        row.push_back(Direction::NORTH_EAST);
        row.push_back(Direction::NORTH_WEST);
        row.push_back(Direction::GROUND);
        row.push_back(Direction::GROUND);
        row.push_back(Direction::GROUND);
        complexDirections->push_back(row);
    }
};

TEST_F(DistanceCalculatorFixture, initializeCorrectDistanceMatrixEasy) {
    distanceCalculator = new DistanceCalculator(*easyDirections);
    distanceMatrix distances = distanceCalculator->getDistances();
    CustomDistanceMatrix expectedDistances(5, 5);
    expectedDistances[1][1] = 0;
    ASSERT_EQ(distances, expectedDistances);
}

TEST_F(DistanceCalculatorFixture, initializeCorrectDistanceMatrixComplex) {
    distanceCalculator = new DistanceCalculator(*complexDirections);
    distanceMatrix distances = distanceCalculator->getDistances();
    CustomDistanceMatrix expectedDistances(5, 5);
    expectedDistances[2][0] = 0;
    ASSERT_EQ(distances, expectedDistances);
}

TEST_F(DistanceCalculatorFixture, calculateMaxDistanceEasy) {
    distanceCalculator = new DistanceCalculator(*easyDirections);
    int maxDistance = distanceCalculator->calculateMaxDistance();
    ASSERT_EQ(maxDistance, 4);
}

TEST_F(DistanceCalculatorFixture, calculateMaxDistanceComplex) {
    distanceCalculator = new DistanceCalculator(*complexDirections);
    int maxDistance = distanceCalculator->calculateMaxDistance();
    ASSERT_EQ(maxDistance, 8);
}
