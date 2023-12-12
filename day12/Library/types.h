//
// Created by sebas on 12.12.2023.
//

#ifndef DAY12_TYPES_H
#define DAY12_TYPES_H

#include <cstdint>
#include <string>
#include <vector>

using springNums = std::vector<uint16_t>;
using informationLine = std::pair<std::string, springNums>;
using informationLines = std::vector<informationLine>;
using lineToTest = std::pair<std::vector<uint16_t>, springNums >;

#endif //DAY12_TYPES_H
