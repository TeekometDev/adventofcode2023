//
// Created by sebas on 11.12.2023.
//

#ifndef DAY11_TYPES_H
#define DAY11_TYPES_H

#include <string>
#include <vector>
#include <iostream>

using line = std::vector<char>;
using grid = std::vector<line>;

using spaceLine = std::vector<bool>;
using spaceGrid = std::vector<spaceLine>;

using position = std::pair<unsigned int, unsigned int>;
using listOfPositions = std::vector<position>;

#endif //DAY11_TYPES_H
