#include <iostream>
#include "FileReader.h"
#include "SpringCalculator.h"

int main() {
    FileReader *reader = new FileReader();
    SpringCalculator *calculator = new SpringCalculator();
    informationLines input = reader->read("data.txt");
    std::cout << calculator->calculate(input) << std::endl;
    return 0;
}
