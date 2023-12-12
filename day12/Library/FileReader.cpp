//
// Created by sebas on 12.12.2023.
//

#include "FileReader.h"

informationLines FileReader::read(const std::string &path) {
    std::ifstream file(path);
    informationLines lines;
    std::string line;
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string symbols;
        iss >> symbols;
        springNums nums;
        std::string stringNums;
        iss >> stringNums;
        uint16_t currentNum = 0;
        for (char c : stringNums) {
            if (c == ',') {
                nums.push_back(currentNum);
                currentNum = 0;
            } else {
                currentNum = currentNum * 10 + (c - '0');
            }
        }
        nums.push_back(currentNum);
        lines.push_back(std::make_pair(symbols, nums));
    }
    return lines;
}