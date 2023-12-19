//
// Created by sebas on 19.12.2023.
//

#include "HashMap.h"
#include "gtest/gtest.h"
#include "FileReader.h"

TEST(Task2Test, Task2Test1) {
    FileReader fileReader;
    stringlist input = fileReader.read("Google-Tests/input_test.txt");
    HashMap hashMap;
    ASSERT_EQ(hashMap.calculateFocalLength(input), 145);
}