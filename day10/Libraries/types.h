//
// Created by sebas on 10.12.2023.
//

#ifndef DAY10_TYPES_H
#define DAY10_TYPES_H

#include <vector>

using distanceRow = std::vector<int>;
using distanceMatrix = std::vector<distanceRow>;

enum class Direction {
    VERTICAL = '|',
    HORIZONTAL = '-',
    NORTH_EAST = 'L',
    NORTH_WEST = 'J',
    SOUTH_EAST = 'F',
    SOUTH_WEST = '7',
    GROUND = '.',
    START = 'S'
};

enum SourceDirection {
    NORTH,
    EAST,
    SOUTH,
    WEST
};

using position = std::pair<int, int>;

typedef struct {
    position lastPosition;
    position currentPosition;
    SourceDirection sourceDirection;
} positionInfo;

using setOfPositions = std::vector<positionInfo>;

using directionRow = std::vector<Direction>;
using directionMatrix = std::vector<directionRow>;

class CustomDistanceMatrix: public distanceMatrix {
public:
    CustomDistanceMatrix(int rows, int columns) {
        for (int i = 0; i < rows; i++) {
            distanceRow row;
            for (int j = 0; j < columns; j++) {
                row.push_back(-1);
            }
            this->push_back(row);
        }
    }
};

#endif //DAY10_TYPES_H
