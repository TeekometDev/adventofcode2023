#include <iostream>
#include "FileReader.h"
#include "HashAlgorithm.h"
#include "HashMap.h"

int main() {
    std::cout << "Advent of Code 2023 - Day 15" << std::endl;
    FileReader *reader = new FileReader();
    HashAlgorithm *algorithm = new HashAlgorithm();
    stringlist input = reader->read("data.txt");
    std::cout << "Task 1: " << std::endl;
    std::cout << algorithm->calculateHashValue(input) << std::endl;
    std::cout << "Task 2: " << std::endl;
    HashMap *map = new HashMap();
    input = reader->read("data.txt");
    std::cout << map->calculateFocalLength(input) << std::endl;
    return 0;
}
