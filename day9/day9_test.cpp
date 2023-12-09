//
// Created by sebas on 09.12.2023.
//

#include <iostream>
#include "FileReader.h"
#include "ExtrapolationCalculator.h"

int main() {
    FileReader fileReader;
    matrixOfWork readMatrix = fileReader.readFile("test.txt");
    ExtrapolationCalculator extrapolationCalculator;
    int result = extrapolationCalculator.calculate(readMatrix);
    std::cout << "Test1: " << result << std::endl;
    if (result == 114) {
        std::cout << "Test passed!" << std::endl;
    } else {
        std::cout << "Test failed!" << std::endl;
    }
    result = extrapolationCalculator.getBackwardValue();
    std::cout << "Test2: " << result << std::endl;
    if (result == 2) {
        std::cout << "Test passed!" << std::endl;
    } else {
        std::cout << "Test failed!" << std::endl;
    }
    return 0;
}