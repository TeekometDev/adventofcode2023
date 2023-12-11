#include <iostream>
#include "FileReader.h"
#include "SpaceDistanceCalculator.h"

int main() {
    FileReader reader;
    SpaceDistanceCalculator calculator;
    spaceGrid grid = reader.read("puzzle-input.txt");
    int distance = calculator.calculate(grid);
    std::cout << "Distance: " << distance << std::endl;
    unsigned long long distance2 = calculator.expandedUniverseCalculation(grid, 1000000);
    std::cout << "Distance2: " << distance2 << std::endl;
    return 0;
}
