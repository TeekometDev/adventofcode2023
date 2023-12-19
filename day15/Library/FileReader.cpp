//
// Created by sebas on 12.12.2023.
//

#include "FileReader.h"

stringlist FileReader::read(const std::string &path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }
    stringlist lines;
    std::string line, lineAddition;
    std::getline(file, line);
    for (char c : line) {
        if (c == ',') {
            lines.push_back(lineAddition);
            lineAddition = "";
        } else {
            lineAddition += c;
        }
    }
    lines.push_back(lineAddition);
    return lines;
}