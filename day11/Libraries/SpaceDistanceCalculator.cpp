//
// Created by sebas on 11.12.2023.
//

#include "SpaceDistanceCalculator.h"

SpaceDistanceCalculator::SpaceDistanceCalculator() {
    this->positionList = new listOfPositions();
}

int SpaceDistanceCalculator::calculate(spaceGrid &grid) {
    this->finalGrid = this->expandGrid(grid);
    this->getPositions();
    int distance = 0;

    for (int i = 0; i < this->positionList->size(); i++) {
        int tempDistance = 0;
        for (int j = i + 1; j < this->positionList->size(); j++) {
            tempDistance += abs(this->positionList->at(i).first - this->positionList->at(j).first) +
                           abs(this->positionList->at(i).second - this->positionList->at(j).second);
        }
        distance += tempDistance;
    }
    return distance;
}

unsigned long long SpaceDistanceCalculator::expandedUniverseCalculation(spaceGrid &grid, int factor) {
    int numOfEmptyLines = 0;
    this->positionList = new listOfPositions();

    for (int i = 0; i < grid.size(); i++) {
        if (this->isEmptyLine(grid[i])) {
            numOfEmptyLines++;
        } else {
            int numOfEmptyColumns = 0;
            for (int j = 0; j < grid[i].size(); j++) {
                if (this->isEmptyColumn(grid, j)) {
                    numOfEmptyColumns++;
                } else {
                    if (grid[i][j]) {
                        unsigned int xPos = i + numOfEmptyLines * factor - numOfEmptyLines;
                        unsigned int yPos = j + numOfEmptyColumns * factor - numOfEmptyColumns;
                        this->positionList->push_back(std::make_pair(xPos, yPos));
                    }
                }
            }
        }
    }

    unsigned long long distance = 0;
    for (int i = 0; i < this->positionList->size(); i++) {
        int tempDistance = 0;
        for (int j = i + 1; j < this->positionList->size(); j++) {
            tempDistance += abs(this->positionList->at(i).first - this->positionList->at(j).first) +
                            abs(this->positionList->at(i).second - this->positionList->at(j).second);
        }
        distance += tempDistance;
    }
    return distance;
}

spaceGrid SpaceDistanceCalculator::expandGrid(spaceGrid &grid) {
    spaceGrid newSpaceGrid = grid;
    // Expand Empty Lines
    for (int i = 0; i < newSpaceGrid.size(); i++) {
        bool hasGalaxy = false;
        for (int j = 0; j < newSpaceGrid[i].size(); j++) {
            if (newSpaceGrid[i][j]) {
                hasGalaxy = true;
                break;
            }
        }
        if (!hasGalaxy) {
            newSpaceGrid.insert(newSpaceGrid.begin() + i, spaceLine(newSpaceGrid[i].size(), false));
            i++;
        }
    }
    // Expand Empty Columns
    for (int i = 0; i < newSpaceGrid[0].size(); i++) {
        bool hasGalaxy = false;
        for (int j = 0; j < newSpaceGrid.size(); j++) {
            if (newSpaceGrid[j][i]) {
                hasGalaxy = true;
                break;
            }
        }
        if (!hasGalaxy) {
            for (int j = 0; j < newSpaceGrid.size(); j++) {
                newSpaceGrid[j].insert(newSpaceGrid[j].begin() + i, false);
            }
            i++;
        }
    }
    return newSpaceGrid;
}

void SpaceDistanceCalculator::getPositions() {
    std::cout << "Getting positions" << std::endl;
    std::cout << "Final Grid size: " << this->finalGrid.size() << " " << this->finalGrid[0].size() << std::endl;
    for (int i = 0; i < this->finalGrid.size(); i++) {
        for (int j = 0; j < this->finalGrid[i].size(); j++) {
            if (this->finalGrid[i][j]) {
                std::cout << "Found position: " << i << " " << j << std::endl;
                this->positionList->push_back(std::make_pair(i, j));
            }
        }
    }
}

bool SpaceDistanceCalculator::isEmptyLine(spaceLine &line) {
    for (bool b : line) {
        if (b) {
            return false;
        }
    }
    return true;
}

bool SpaceDistanceCalculator::isEmptyColumn(spaceGrid &grid, int column) {
    for (int i = 0; i < grid.size(); i++) {
        if (grid[i][column]) {
            return false;
        }
    }
    return true;
}
