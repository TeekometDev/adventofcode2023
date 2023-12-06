//
// Created by sebas on 06.12.2023.
//

#include "gatheringData.h"
#include "Task1_WinningCalc.h"
#include "Task2_Calculations.h"

int main() {
    GatheringData data("data.txt");
    Task1_WinningCalc calc;
    int result = calc.calculatedWinningTraces(data.currentGame);
    std::cout << "Result: " << result << std::endl;
    Task2_Calculations calc2;
    int result2 = calc2.calculateNumberOfPossibilities(data.currentGame);
    std::cout << "Result2: " << result2 << std::endl;
    return 0;
}