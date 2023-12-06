//
// Created by sebas on 06.12.2023.
//

#include "gatheringData.h"
#include "Task1_WinningCalc.h"
#include "Task2_Calculations.h"

int main() {
    GatheringData data("test.txt");
    Task1_WinningCalc calc;
    int result = calc.calculatedWinningTraces(data.currentGame);
    if(result != 288) {
        std::cout << "Test failed" << std::endl;
        return 1;
    } else {
        std::cout << "Test passed" << std::endl;
    }
    Task2_Calculations calc2;
    int result2 = calc2.calculateNumberOfPossibilities(data.currentGame);
    if(result2 != 71503) {
        std::cout << "Test failed" << std::endl;
        return 1;
    } else {
        std::cout << "Test passed" << std::endl;
    }

    return 0;
}