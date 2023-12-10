#include <iostream>
#include "Libraries/FileReader.h"
#include "Libraries/DistanceCalculator.h"

int main() {
    FileReader fileReader;
    directionMatrix readMatrix = fileReader.readFile("data.txt");
    DistanceCalculator distanceCalculator(readMatrix);
    int result = distanceCalculator.calculateMaxDistance();
    std::cout << "Result 1: " << result << std::endl;
    result = distanceCalculator.getLoopedNumber();
    std::cout << "Result 2: " << result << std::endl;
    return 0;
}
