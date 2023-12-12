#include <iostream>
#include "FileReader.h"
#include "SpringCalculator.h"

int main() {
    FileReader *reader = new FileReader();
    SpringCalculator *calculator = new SpringCalculator();
    informationLines input = reader->read("data.txt");
    std::cout << "Task 1: " << std::endl;
    std::cout << calculator->calculateMethod2(input) << std::endl;
    std::cout << "Task 2: " << std::endl;
    std::cout << calculator->calculateTask2Multithreading(input) << std::endl;
    return 0;
}
