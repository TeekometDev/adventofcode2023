//
// Created by sebas on 10.12.2023.
//

#include "DistanceCalculator.h"
#include <iostream>

DistanceCalculator::DistanceCalculator(directionMatrix &directions) {
    this->directions = &directions;
    initDistanceMatrix();
}

int DistanceCalculator::calculateMaxDistance() {
    int result = 0;
    // set nodes to Start Nodes (distance = 1)
    setOfPositions setOfNodes = getStartNodes();
    result++;
    while (setOfNodes[0].currentPosition != setOfNodes[1].currentPosition) {
        setOfPositions newSetOfNodes;
        for (auto &node : setOfNodes) {
            distances->at(node.currentPosition.first).at(node.currentPosition.second) = result;
            newSetOfNodes.push_back(getNextPosition(node));
        }
        setOfNodes = newSetOfNodes;
        result++;
    }
    distances->at(setOfNodes[0].currentPosition.first).at(setOfNodes[0].currentPosition.second) = result;
    this->calculateLoopSpaces();
    return result;
}

void DistanceCalculator::calculateLoopSpaces() {
    int result = 0;
    this->evenOddRuleApproach();
    for (int i = 0; i < this->distances->size(); i++) {
        for (int j = 0; j < this->distances->at(i).size(); j++) {
            if (this->distances->at(i).at(j) == -2) {
                result++;
            }
        }
    }
    this->loopedNumber = result;
}

void DistanceCalculator::evenOddRuleApproach() {
    for (int i = 0; i < this->distances->size(); i++) {
        for (int j = 0; j < this->distances->at(i).size(); j++) {
            if (this->distances->at(i).at(j) == -1) {
                int countCrossings = 0;
                for (int k = j; k < this->distances->at(i).size(); k++) {
                    Direction lastElement;
                    if (this->isVerticalChangeingElement(this->directions->at(i).at(k)) && this->distances->at(i).at(k) != -1) {
                        if (lastElement == Direction::NORTH_EAST && this->directions->at(i).at(k) == Direction::SOUTH_WEST)
                            countCrossings++;
                        if (lastElement == Direction::SOUTH_EAST && this->directions->at(i).at(k) == Direction::NORTH_WEST)
                            countCrossings++;
                        lastElement = this->directions->at(i).at(k);
                        countCrossings++;
                    }
                }
                if (countCrossings % 2 == 1) {
                    this->distances->at(i).at(j) = -2;
                }
            }
        }
    }
}

distanceMatrix DistanceCalculator::getDistances() {
    return *distances;
}

int DistanceCalculator::getLoopedNumber() {
    return this->loopedNumber;
}

void DistanceCalculator::initDistanceMatrix() {
    distances = new CustomDistanceMatrix(this->directions->size(), this->directions->at(0).size());
    for (int i = 0; i < this->directions->size(); i++) {
        for (int j = 0; j < this->directions->at(i).size(); j++) {
            if (this->directions->at(i).at(j) == Direction::START) {
                distances->at(i).at(j) = 0;
                startPosition = std::make_pair(i, j);
            }
        }
    }
}

setOfPositions DistanceCalculator::getStartNodes() {
    setOfPositions startNodes;
    int startDirection = 0;
    if (checkNorth(startPosition)) {
        positionInfo info;
        info.currentPosition = std::make_pair(startPosition.first - 1, startPosition.second);
        info.lastPosition = startPosition;
        info.sourceDirection = SourceDirection::SOUTH;
        startNodes.push_back(info);
        startDirection += 1;
    }
    if (checkEast(startPosition)) {
        positionInfo info;
        info.currentPosition = std::make_pair(startPosition.first, startPosition.second + 1);
        info.lastPosition = startPosition;
        info.sourceDirection = SourceDirection::WEST;
        startNodes.push_back(info);
        startDirection += 10;
    }
    if (checkSouth(startPosition)) {
        positionInfo info;
        info.currentPosition = std::make_pair(startPosition.first + 1, startPosition.second);
        info.lastPosition = startPosition;
        info.sourceDirection = SourceDirection::NORTH;
        startNodes.push_back(info);
        startDirection += 100;
    }
    if (checkWest(startPosition)) {
        positionInfo info;
        info.currentPosition = std::make_pair(startPosition.first, startPosition.second - 1);
        info.lastPosition = startPosition;
        info.sourceDirection = SourceDirection::EAST;
        startNodes.push_back(info);
        startDirection += 1000;
    }
    switch (startDirection) {
        case 11:
            directions->at(startPosition.first).at(startPosition.second) = Direction::NORTH_EAST;
            break;
        case 110:
            directions->at(startPosition.first).at(startPosition.second) = Direction::SOUTH_EAST;
            break;
        case 1100:
            directions->at(startPosition.first).at(startPosition.second) = Direction::SOUTH_WEST;
            break;
        case 1001:
            directions->at(startPosition.first).at(startPosition.second) = Direction::NORTH_WEST;
            break;
        case 101:
            directions->at(startPosition.first).at(startPosition.second) = Direction::VERTICAL;
            break;
        case 1010:
            directions->at(startPosition.first).at(startPosition.second) = Direction::HORIZONTAL;
            break;
    }
    return startNodes;
}

positionInfo DistanceCalculator::getNextPosition(positionInfo &info) {
    positionInfo nextPosition;
    nextPosition.lastPosition = info.currentPosition;
    Direction direction = directions->at(info.currentPosition.first).at(info.currentPosition.second);
    switch (direction) {
        case Direction::VERTICAL:
            if (info.sourceDirection == SourceDirection::NORTH) {
                nextPosition.currentPosition = std::make_pair(info.currentPosition.first + 1, info.currentPosition.second);
                nextPosition.sourceDirection = SourceDirection::NORTH;
            } else {
                nextPosition.currentPosition = std::make_pair(info.currentPosition.first - 1, info.currentPosition.second);
                nextPosition.sourceDirection = SourceDirection::SOUTH;
            }
            break;
        case Direction::HORIZONTAL:
            if (info.sourceDirection == SourceDirection::EAST) {
                nextPosition.currentPosition = std::make_pair(info.currentPosition.first, info.currentPosition.second - 1);
                nextPosition.sourceDirection = SourceDirection::EAST;
            } else {
                nextPosition.currentPosition = std::make_pair(info.currentPosition.first, info.currentPosition.second + 1);
                nextPosition.sourceDirection = SourceDirection::WEST;
            }
            break;
        case Direction::NORTH_EAST:
            if (info.sourceDirection == SourceDirection::NORTH) {
                nextPosition.currentPosition = std::make_pair(info.currentPosition.first, info.currentPosition.second + 1);
                nextPosition.sourceDirection = SourceDirection::WEST;
            } else {
                nextPosition.currentPosition = std::make_pair(info.currentPosition.first - 1, info.currentPosition.second);
                nextPosition.sourceDirection = SourceDirection::SOUTH;
            }
            break;
        case Direction::NORTH_WEST:
            if (info.sourceDirection == SourceDirection::NORTH) {
                nextPosition.currentPosition = std::make_pair(info.currentPosition.first, info.currentPosition.second - 1);
                nextPosition.sourceDirection = SourceDirection::EAST;
            } else {
                nextPosition.currentPosition = std::make_pair(info.currentPosition.first - 1, info.currentPosition.second);
                nextPosition.sourceDirection = SourceDirection::SOUTH;
            }
            break;
        case Direction::SOUTH_EAST:
            if (info.sourceDirection == SourceDirection::SOUTH) {
                nextPosition.currentPosition = std::make_pair(info.currentPosition.first, info.currentPosition.second + 1);
                nextPosition.sourceDirection = SourceDirection::WEST;
            } else {
                nextPosition.currentPosition = std::make_pair(info.currentPosition.first + 1, info.currentPosition.second);
                nextPosition.sourceDirection = SourceDirection::NORTH;
            }
            break;
        case Direction::SOUTH_WEST:
            if (info.sourceDirection == SourceDirection::SOUTH) {
                nextPosition.currentPosition = std::make_pair(info.currentPosition.first, info.currentPosition.second - 1);
                nextPosition.sourceDirection = SourceDirection::EAST;
            } else {
                nextPosition.currentPosition = std::make_pair(info.currentPosition.first + 1, info.currentPosition.second);
                nextPosition.sourceDirection = SourceDirection::NORTH;
            }
            break;
    }
    return nextPosition;
}

bool DistanceCalculator::isVerticalChangeingElement(Direction &direction) {
    return direction == Direction::VERTICAL || direction == Direction::NORTH_EAST || direction == Direction::NORTH_WEST ||
           direction == Direction::SOUTH_EAST || direction == Direction::SOUTH_WEST;
}

bool DistanceCalculator::checkNorth(position currentPosition) {
    if (currentPosition.first > 0) {
        Direction fieldValue = directions->at(currentPosition.first - 1).at(currentPosition.second);
        if (fieldValue == Direction::VERTICAL || fieldValue == Direction::SOUTH_EAST || fieldValue == Direction::SOUTH_WEST) {
            return true;
        }
    }
    return false;
}

bool DistanceCalculator::checkEast(position currentPosition) {
    if (currentPosition.second < directions->at(currentPosition.first).size() - 1) {
        Direction fieldValue = directions->at(currentPosition.first).at(currentPosition.second + 1);
        if (fieldValue == Direction::HORIZONTAL || fieldValue == Direction::NORTH_WEST || fieldValue == Direction::SOUTH_WEST) {
            return true;
        }
    }
    return false;
}

bool DistanceCalculator::checkSouth(position currentPosition) {
    if (currentPosition.first < directions->size() - 1) {
        Direction fieldValue = directions->at(currentPosition.first + 1).at(currentPosition.second);
        if (fieldValue == Direction::VERTICAL || fieldValue == Direction::NORTH_EAST || fieldValue == Direction::NORTH_WEST) {
            return true;
        }
    }
    return false;
}

bool DistanceCalculator::checkWest(position currentPosition) {
    if (currentPosition.second > 0) {
        Direction fieldValue = directions->at(currentPosition.first).at(currentPosition.second - 1);
        if (fieldValue == Direction::HORIZONTAL || fieldValue == Direction::NORTH_EAST || fieldValue == Direction::SOUTH_EAST) {
            return true;
        }
    }
    return false;
}
