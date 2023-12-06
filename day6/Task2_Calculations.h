//
// Created by sebas on 06.12.2023.
//

#ifndef DAY6_TASK2_CALCULATIONS_H
#define DAY6_TASK2_CALCULATIONS_H
#include "gatheringData.h"

class Task2_Calculations {
public:
    Task2_Calculations();
    ~Task2_Calculations();
    int calculateNumberOfPossibilities(std::vector<GAMEDATA>& games);
private:
    GAMEDATA mergeNumbers(std::vector<GAMEDATA>& games);
};


#endif //DAY6_TASK2_CALCULATIONS_H
