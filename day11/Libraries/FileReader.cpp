//
// Created by sebas on 11.12.2023.
//

#include "FileReader.h"

spaceGrid FileReader::read(std::string filename) {
    std::ifstream file(filename);
    std::string line;
    spaceGrid grid;
    if (!file.is_open()) {
        std::cerr << "File not found" << std::endl;
        return grid;
    }
    while (std::getline(file, line)) {
        spaceLine spaceLine;
        for (char c : line) {
            if (c == '.') {
                spaceLine.push_back(false);
            } else if (c == '#') {
                spaceLine.push_back(true);
            }
        }
        grid.push_back(spaceLine);
    }
    return grid;
}