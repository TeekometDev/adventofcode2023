//
// Created by sebas on 10.12.2023.
//

#include "FileReader.h"

directionMatrix FileReader::readFile(std::string fileName) {
    directionMatrix matrix;
    directionRow row;
    std::ifstream file(fileName);
    std::string line;
    if (!file.is_open()) {
        std::cerr << "File not found!" << std::endl;
        return matrix;
    }
    while (std::getline(file, line)) {
        for (char &c : line) {
            switch (c) {
                case 'S':
                    row.push_back(Direction::START);
                    break;
                case '|':
                    row.push_back(Direction::VERTICAL);
                    break;
                case '-':
                    row.push_back(Direction::HORIZONTAL);
                    break;
                case 'L':
                    row.push_back(Direction::NORTH_EAST);
                    break;
                case 'J':
                    row.push_back(Direction::NORTH_WEST);
                    break;
                case 'F':
                    row.push_back(Direction::SOUTH_EAST);
                    break;
                case '7':
                    row.push_back(Direction::SOUTH_WEST);
                    break;
                default:
                    row.push_back(Direction::GROUND);
                    break;
            }
        }
        matrix.push_back(row);
        row.clear();
    }
    file.close();
    return matrix;
}
