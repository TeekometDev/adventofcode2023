//
// Created by sebas on 09.12.2023.
//

#include "FileReader.h"

matrixOfWork FileReader::readFile(std::string fileName) {
    std::ifstream file(fileName);
    matrixOfWork matrix;
    if  (file.is_open())    {
        std::string line;
        std::string token;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            calculationLine calculation;
            while (std::getline(iss, token, ' ')) {
                calculation.push_back(std::stoi(token));
            }
            calculatedLines tempLines;
            tempLines.push_back(calculation);
            matrix.push_back(tempLines);
        }
    } else {
        std::cerr << "Could not open file: " << fileName << std::endl;
    }
    file.close();
    return matrix;
}