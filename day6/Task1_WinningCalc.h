//
// Created by sebas on 06.12.2023.
//

#ifndef DAY6_TASK1_WINNINGCALC_H
#define DAY6_TASK1_WINNINGCALC_H

#include <iostream>
#include <vector>
#include <cmath>
#include "gatheringData.h"

class Task1_WinningCalc {
public:
    Task1_WinningCalc();
    ~Task1_WinningCalc();
    int calculatedWinningTraces(std::vector<GAMEDATA>& games);
};


#endif //DAY6_TASK1_WINNINGCALC_H
