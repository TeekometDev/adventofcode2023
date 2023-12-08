//
// Created by sebas on 08.12.2023.
//

#include <iostream>
#include "FileReader.h"
#include "Pathfinder.h"

int main() {
    FileReader fileReader;
    fileReader.readPathsFromFile("test.txt");
    Pathfinder pathfinder;
    int result = pathfinder.findPath(fileReader.getInstructions(), fileReader.getNodelist());
    std::cout << "Task1: " << result << std::endl;
    if(result == 2) {
        std::cout << "Test 1 passed!" << std::endl;
    } else {
        std::cerr << "Test 1 failed!" << std::endl;
        return 1;
    }
    fileReader.readPathsFromFile("test_1.txt");
    result = pathfinder.findPath(fileReader.getInstructions(), fileReader.getNodelist());
    std::cout << "Task2: " << result << std::endl;
    if(result == 6) {
        std::cout << "Test 2 passed!" << std::endl;
    } else {
        std::cerr << "Test 2 failed!" << std::endl;
        return 1;
    }
    fileReader.readPathsFromFile("test_2.txt");
    result = pathfinder.findGhostPath(fileReader.getInstructions(), fileReader.getNodelist());
    std::cout << "Task3: " << result << std::endl;
    if(result == 6) {
        std::cout << "Test 3 passed!" << std::endl;
    } else {
        std::cerr << "Test 3 failed!" << std::endl;
        return 1;
    }
    return 0;
}