//
// Created by sebas on 12.12.2023.
//

#ifndef DAY12_SPRINGCALCULATOR_H
#define DAY12_SPRINGCALCULATOR_H

#include "types.h"

class SpringCalculator {
public:
    uint32_t calculate(const informationLines &input);
    uint32_t calculateMethod2(const informationLines &input);
    uint64_t calculateTask2(const informationLines &input);
private:
    lineToTest convertLineToTest(const std::string &line, const springNums &springNums);
    std::vector<std::string> removeQuestionMarks(const std::string line);
    uint64_t countValid(informationLine input, const uint64_t iterations);
};


#endif //DAY12_SPRINGCALCULATOR_H
