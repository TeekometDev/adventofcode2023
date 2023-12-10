//
// Created by sebas on 10.12.2023.
//

#include "DistanceCalculator.h"
#include "FileReader.h"
#include "gtest/gtest.h"

class LoopCalculatorFixture : public ::testing::Test {
public:
    virtual void SetUp() {
        fileReader = new FileReader();
    }
    virtual void TearDown() {
        delete fileReader;
        delete distanceCalculator;
    }
    FileReader* fileReader;
    DistanceCalculator* distanceCalculator;
};

TEST_F(LoopCalculatorFixture, getLoopTest1Correctly) {
    directionMatrix readMatrix = fileReader->readFile("Google-Tests/looptest1.txt");
    distanceCalculator = new DistanceCalculator(readMatrix);
    distanceCalculator->calculateMaxDistance();
    distanceMatrix resultMatrix = distanceCalculator->getDistances();
    for (int i = 0; i < resultMatrix.size(); i++) {
        for (int j = 0; j < resultMatrix[i].size(); j++) {
            std::cout << resultMatrix[i][j] << "|";
        }
        std::cout << std::endl;
    }
    ASSERT_EQ(distanceCalculator->getLoopedNumber(), 4);
}

TEST_F(LoopCalculatorFixture, getLoopTest2Correctly) {
    directionMatrix readMatrix = fileReader->readFile("Google-Tests/looptest2.txt");
    distanceCalculator = new DistanceCalculator(readMatrix);
    distanceCalculator->calculateMaxDistance();
    distanceMatrix resultMatrix = distanceCalculator->getDistances();
    for (int i = 0; i < resultMatrix.size(); i++) {
        for (int j = 0; j < resultMatrix[i].size(); j++) {
            std::cout << resultMatrix[i][j] << "|";
        }
        std::cout << std::endl;
    }
    ASSERT_EQ(distanceCalculator->getLoopedNumber(), 8);
}

TEST_F(LoopCalculatorFixture, getLoopTest3Correctly) {
    directionMatrix readMatrix = fileReader->readFile("Google-Tests/looptest3.txt");
    distanceCalculator = new DistanceCalculator(readMatrix);
    distanceCalculator->calculateMaxDistance();
    ASSERT_EQ(distanceCalculator->getLoopedNumber(), 10);
}
