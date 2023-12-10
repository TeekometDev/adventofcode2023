//
// Created by sebas on 10.12.2023.
//

#ifndef DAY10_DISTANCECALCULATOR_H
#define DAY10_DISTANCECALCULATOR_H

#include "types.h"

class DistanceCalculator {
public:
    DistanceCalculator(directionMatrix &directions);
    int calculateMaxDistance();
    int getLoopedNumber();
    distanceMatrix getDistances();
private:
    CustomDistanceMatrix* distances;
    directionMatrix* directions;
    position startPosition;
    int loopedNumber = 0;
    void initDistanceMatrix();
    void calculateLoopSpaces();
    void evenOddRuleApproach();
    setOfPositions getStartNodes();
    positionInfo getNextPosition(positionInfo &info);
    bool isVerticalChangeingElement(Direction &direction);
    bool checkNorth(position currentPosition);
    bool checkEast(position currentPosition);
    bool checkSouth(position currentPosition);
    bool checkWest(position currentPosition);
};


#endif //DAY10_DISTANCECALCULATOR_H
