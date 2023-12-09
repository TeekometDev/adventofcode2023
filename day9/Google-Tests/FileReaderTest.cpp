//
// Created by sebas on 09.12.2023.
//

#include "FileReader.h"
#include "gtest/gtest.h"

class FileReaderFixture : public ::testing::Test {
protected:
    virtual void SetUp() {
        fileReader = new FileReader();
        resultingMatrix = new matrixOfWork();
        calculationLine line;
        calculatedLines lines;
        line.push_back(0);
        line.push_back(3);
        line.push_back(6);
        line.push_back(9);
        line.push_back(12);
        line.push_back(15);
        lines.push_back(line);
        resultingMatrix->push_back(lines);
        line.clear();
        lines.clear();
        line.push_back(1);
        line.push_back(3);
        line.push_back(6);
        line.push_back(10);
        line.push_back(15);
        line.push_back(21);
        lines.push_back(line);
        resultingMatrix->push_back(lines);
        line.clear();
        lines.clear();
        line.push_back(10);
        line.push_back(13);
        line.push_back(16);
        line.push_back(21);
        line.push_back(30);
        line.push_back(45);
        lines.push_back(line);
        resultingMatrix->push_back(lines);
    }
    virtual void TearDown() {
        delete fileReader;
    }
    FileReader* fileReader;
    matrixOfWork *resultingMatrix;
};


TEST_F(FileReaderFixture, getCorrectValues) {
    matrixOfWork readMatrix = fileReader->readFile("test.txt");
    ASSERT_EQ(readMatrix, *resultingMatrix);
}
