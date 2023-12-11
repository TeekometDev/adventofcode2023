//
// Created by sebas on 11.12.2023.
//

#ifndef DAY11_SPACEDISTANCECALCULATOR_H
#define DAY11_SPACEDISTANCECALCULATOR_H

#include "types.h"

class SpaceDistanceCalculator {
public:
    SpaceDistanceCalculator();
    int calculate(spaceGrid &grid);
    unsigned long long expandedUniverseCalculation(spaceGrid &grid, int factor);
private:
    spaceGrid expandGrid(spaceGrid &grid);
    void getPositions();
    bool isEmptyLine(spaceLine &line);
    bool isEmptyColumn(spaceGrid &grid, int column);
    spaceGrid finalGrid;
    listOfPositions *positionList;
};


#endif //DAY11_SPACEDISTANCECALCULATOR_H
