#include <iostream>
#include "FileReader.h"
#include "Pathfinder.h"

int main() {
    FileReader fileReader;
    fileReader.readPathsFromFile("data.txt");
    Pathfinder pathfinder;
    int result = pathfinder.findPath(fileReader.getInstructions(), fileReader.getNodelist());
    std::cout << "Task1: " << result << std::endl;
    long long result2 = pathfinder.findGhostPath(fileReader.getInstructions(), fileReader.getNodelist());
    std::cout << "Task2: " << result2 << std::endl;
    return 0;
}
