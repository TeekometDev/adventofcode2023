//
// Created by sebas on 12.12.2023.
//

#include "gtest/gtest.h"
#include "FileReader.h"
#include "HashAlgorithm.h"

TEST(Task1Test, ReadCorrectNumberOfLines) {
    FileReader fileReader;
    stringlist input = fileReader.read("Google-Tests/input_test.txt");
    ASSERT_EQ(input.size(), 11);
}

TEST(Task1Test, ReadCorrectLines) {
    FileReader fileReader;
    stringlist input = fileReader.read("Google-Tests/input_test.txt");
    ASSERT_EQ(input[0], "rn=1");
    ASSERT_EQ(input[1], "cm-");
    ASSERT_EQ(input[2], "qp=3");
    ASSERT_EQ(input[3], "cm=2");
    ASSERT_EQ(input[4], "qp-");
    ASSERT_EQ(input[5], "pc=4");
    ASSERT_EQ(input[6], "ot=9");
    ASSERT_EQ(input[7], "ab=5");
    ASSERT_EQ(input[8], "pc-");
    ASSERT_EQ(input[9], "pc=6");
    ASSERT_EQ(input[10], "ot=7");
}

TEST(Task1Test, CalculateHashValueForTestFile) {
    FileReader fileReader;
    stringlist input = fileReader.read("Google-Tests/input_test.txt");
    HashAlgorithm hashAlgorithm;
    ASSERT_EQ(hashAlgorithm.calculateHashValue(input), 1320);
}

TEST(Task1Test, CalculateHashValueForStringHash) {
    HashAlgorithm hashAlgorithm;
    stringlist input = {"HASH"};
    ASSERT_EQ(hashAlgorithm.calculateHashValue(input), 52);
}
