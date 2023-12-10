//
// Created by sebas on 10.12.2023.
//

#include "gtest/gtest.h"
#include "FileReader.h"

class FileReaderFixture : public ::testing::Test {
protected:
    virtual void SetUp() {
        fileReader = new FileReader();
    }
    virtual void TearDown() {
        delete fileReader;
    }
    FileReader* fileReader;
};

TEST_F(FileReaderFixture, getEasyTestCorrectly) {
    directionMatrix readMatrix = fileReader->readFile("Google-Tests/easy-test.txt");
    directionMatrix expectedMatrix;
    directionRow row;
    for (int i = 0; i< 5; i++) {
        row.push_back(Direction::GROUND);
    }
    expectedMatrix.push_back(row);
    row.clear();
    row.push_back(Direction::GROUND);
    row.push_back(Direction::START);
    row.push_back(Direction::HORIZONTAL);
    row.push_back(Direction::SOUTH_WEST);
    row.push_back(Direction::GROUND);
    expectedMatrix.push_back(row);
    row.clear();
    row.push_back(Direction::GROUND);
    row.push_back(Direction::VERTICAL);
    row.push_back(Direction::GROUND);
    row.push_back(Direction::VERTICAL);
    row.push_back(Direction::GROUND);
    expectedMatrix.push_back(row);
    row.clear();
    row.push_back(Direction::GROUND);
    row.push_back(Direction::NORTH_EAST);
    row.push_back(Direction::HORIZONTAL);
    row.push_back(Direction::NORTH_WEST);
    row.push_back(Direction::GROUND);
    expectedMatrix.push_back(row);
    row.clear();
    for (int i = 0; i< 5; i++) {
        row.push_back(Direction::GROUND);
    }
    expectedMatrix.push_back(row);
    ASSERT_EQ(readMatrix, expectedMatrix);
}

TEST_F(FileReaderFixture, getComplexTestCorrectly) {
    directionMatrix readMatrix = fileReader->readFile("Google-Tests/complex-test.txt");
    directionMatrix expectedMatrix;
    directionRow row;
    row.push_back(Direction::GROUND);
    row.push_back(Direction::GROUND);
    row.push_back(Direction::SOUTH_EAST);
    row.push_back(Direction::SOUTH_WEST);
    row.push_back(Direction::GROUND);
    expectedMatrix.push_back(row);
    row.clear();
    row.push_back(Direction::GROUND);
    row.push_back(Direction::SOUTH_EAST);
    row.push_back(Direction::NORTH_WEST);
    row.push_back(Direction::VERTICAL);
    row.push_back(Direction::GROUND);
    expectedMatrix.push_back(row);
    row.clear();
    row.push_back(Direction::START);
    row.push_back(Direction::NORTH_WEST);
    row.push_back(Direction::GROUND);
    row.push_back(Direction::NORTH_EAST);
    row.push_back(Direction::SOUTH_WEST);
    expectedMatrix.push_back(row);
    row.clear();
    row.push_back(Direction::VERTICAL);
    row.push_back(Direction::SOUTH_EAST);
    row.push_back(Direction::HORIZONTAL);
    row.push_back(Direction::HORIZONTAL);
    row.push_back(Direction::NORTH_WEST);
    expectedMatrix.push_back(row);
    row.clear();
    row.push_back(Direction::NORTH_EAST);
    row.push_back(Direction::NORTH_WEST);
    row.push_back(Direction::GROUND);
    row.push_back(Direction::GROUND);
    row.push_back(Direction::GROUND);
    expectedMatrix.push_back(row);

    ASSERT_EQ(readMatrix, expectedMatrix);
}

