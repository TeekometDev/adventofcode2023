//
// Created by sebas on 12.12.2023.
//

#include "gtest/gtest.h"
#include "SpringCalculator.h"
#include "FileReader.h"

class Day12Task1Fixture : public ::testing::Test {
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

TEST_F(Day12Task1Fixture, Task1ReaderTestSpringNums) {
    informationLines input = reader->read("Google-Tests/test.txt");
    ASSERT_EQ(input[0].second, std::vector<uint16_t>({1,1,3}));
    ASSERT_EQ(input[1].second, std::vector<uint16_t>({1,1,3}));
    ASSERT_EQ(input[2].second, std::vector<uint16_t>({1,3,1,6}));
    ASSERT_EQ(input[3].second, std::vector<uint16_t>({4,1,1}));
    ASSERT_EQ(input[4].second, std::vector<uint16_t>({1,6,5}));
    ASSERT_EQ(input[5].second, std::vector<uint16_t>({3,2,1}));
}

TEST_F(Day12Task1Fixture, Task1ReaderTestSymbols) {
    informationLines input = reader->read("Google-tests/test.txt");
    ASSERT_EQ(input[0].first, "???.###");
    ASSERT_EQ(input[1].first, ".??..??...?##.");
    ASSERT_EQ(input[2].first, "?#?#?#?#?#?#?#?");
    ASSERT_EQ(input[3].first, "????.#...#...");
    ASSERT_EQ(input[4].first, "????.######..#####.");
    ASSERT_EQ(input[5].first, "?###????????");
}

TEST_F(Day12Task1Fixture, Task1Test1) {
    informationLines input = reader->read("Google-tests/test.txt");
    ASSERT_EQ(calculator->calculate(input), 21);
}
