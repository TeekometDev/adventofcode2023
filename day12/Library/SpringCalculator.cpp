//
// Created by sebas on 12.12.2023.
//

#include "SpringCalculator.h"
#include <iostream>

void parallelCountValid(SpringCalculator *calculator,const informationLine &line) {
    uint64_t tempSum = calculator->countValid(line, 0);
    std::lock_guard<std::mutex> lock(calculator->mutex);
    calculator->sum += tempSum;
}

uint32_t SpringCalculator::calculate(const informationLines &input) {
    std::vector<lineToTest> linesToTest;
    for (const informationLine &line : input) {
        std::vector<std::string> tempLines;
        tempLines = this->removeQuestionMarks(line.first);
        for (const std::string &tempLine : tempLines) {
            linesToTest.push_back(this->convertLineToTest(tempLine, line.second));
        }
    }
    uint32_t sum = 0;
    for (const lineToTest &line : linesToTest) {
        if (line.first == line.second) {
            sum++;
        }
    }
    return sum;
}

lineToTest SpringCalculator::convertLineToTest(const std::string &line, const springNums &springNums) {
    std::vector<uint16_t> nums;
    uint16_t currentNum = 0;
    for (char c : line) {
        if (c == '#') {
            currentNum++;
        } else {
            if (currentNum != 0) {
                nums.push_back(currentNum);
            }
            currentNum = 0;
        }
    }
    if (currentNum != 0) {
        nums.push_back(currentNum);
    }
    return std::make_pair(nums, springNums);
}

std::vector<std::string> SpringCalculator::removeQuestionMarks(const std::string line) {
    std::vector<std::string> lines;
    for (int i = 0; i < line.size(); i++) {
        char c = line[i];
        if (c == '?') {
            std::string tempLine(line.size(), ' ');
            std::copy(line.begin(), line.end(), tempLine.begin());
            std::vector<std::string> noSpringBased = this->removeQuestionMarks(tempLine.replace(i, 1, "."));
            std::vector<std::string> springBased = this->removeQuestionMarks(tempLine.replace(i, 1, "#"));
            lines.insert(lines.end(), noSpringBased.begin(), noSpringBased.end());
            lines.insert(lines.end(), springBased.begin(), springBased.end());
            break;
        }
    }
    if (lines.empty()) {
        lines.push_back(line);
    }
    return lines;
}

uint32_t SpringCalculator::calculateMethod2(const informationLines &input) {
    uint64_t sum = 0;
    for (const informationLine &line : input) {
        uint64_t tempSum = this->countValid(line, 0);
        sum += tempSum;
    }
    return sum;
}

uint64_t SpringCalculator::calculateTask2(const informationLines &input) {
    informationLines expandedInput;
    for (const informationLine &line : input) {
        std::string expandedLine = line.first;
        springNums expandedNums = line.second;
        for (int i = 0; i < 4; i++) {
            expandedLine += "?" + line.first;
            for (uint16_t num : line.second) {
                expandedNums.push_back(num);
            }
        }
        expandedInput.push_back(std::make_pair(expandedLine, expandedNums));
    }
    uint64_t sum = 0;
    for (const informationLine &line : expandedInput) {
        uint64_t tempSum = this->countValid(line, 0);
        sum += tempSum;
    }
    return sum;
}

uint64_t SpringCalculator::calculateTask2Multithreading(const informationLines &input) {
    informationLines expandedInput;
    for (const informationLine &line : input) {
        std::string expandedLine = line.first;
        springNums expandedNums = line.second;
        for (int i = 0; i < 4; i++) {
            expandedLine += "?" + line.first;
            for (uint16_t num : line.second) {
                expandedNums.push_back(num);
            }
        }
        expandedInput.push_back(std::make_pair(expandedLine, expandedNums));
    }
    std::vector<std::thread> threads;
    for (const informationLine &line : expandedInput) {
        threads.emplace_back(parallelCountValid, this, line);
    }

    for (std::thread &thread : threads) {
        thread.join();
    }

    return sum.load();
}

uint64_t SpringCalculator::countValid(informationLine input, const uint64_t iterations) {
    if (input.first.size() == 0) {
        return (input.second.size() == 1 && input.second[0] == iterations) || (input.second.empty() && iterations == 0) ? 1 : 0;
    }

    char c = input.first[0];
    std::string tempLine = input.first;
    if (c == '?') {
        tempLine.erase(tempLine.begin());
        informationLine spring = std::make_pair('#' + tempLine, input.second);
        informationLine noSpring = std::make_pair('.' + tempLine, input.second);
        return this->countValid(spring, iterations) + this->countValid(noSpring, iterations);
    } else if (c == '#') {
        tempLine.erase(tempLine.begin());
        return this->countValid(std::make_pair(tempLine, input.second), iterations + 1);
    } else if (iterations == 0) {
        tempLine.erase(tempLine.begin());
        return this->countValid(std::make_pair(tempLine, input.second), 0);
    } else if (!input.second.empty() && iterations == input.second[0]) {
        tempLine.erase(tempLine.begin());
        std::vector secondCopy = input.second;
        secondCopy.erase(secondCopy.begin());
        return this->countValid(std::make_pair(tempLine, secondCopy), 0);
    } else if (input.second.empty()) {
        tempLine.erase(tempLine.begin());
        return this->countValid(std::make_pair(tempLine, input.second), iterations);
    } else {
        return 0;
    }
}
