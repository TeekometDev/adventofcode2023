#include <iostream>

#include "Libraries/FileReader.h"
#include "Libraries/ExtrapolationCalculator.h"

int main() {
    FileReader fileReader;
    matrixOfWork readMatrix = fileReader.readFile("data.txt");
    ExtrapolationCalculator extrapolationCalculator;
    int result = extrapolationCalculator.calculate(readMatrix);
    std::cout << "Result 1: " << result << std::endl;
    result = extrapolationCalculator.getBackwardValue();
    std::cout << "Result 2: " << result << std::endl;
    return 0;
}
