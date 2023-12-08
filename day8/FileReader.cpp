//
// Created by sebas on 08.12.2023.
//

#include "FileReader.h"
#include <iostream>

void FileReader::readPathsFromFile(const std::string &fileName) {
    std::ifstream file(fileName);
    std::string line;
    std::getline(file, line);
    this->instructions = line;
    this->nodelist.clear();

    // remove empty line
    std::getline(file, line);
    const std::regex unnecessaryChars("[=,\n()]");

    while (std::getline(file, line)) {
        std::stringstream result;
        std::regex_replace(std::ostream_iterator<char>(result), line.begin(), line.end(), unnecessaryChars, "");
        std::istringstream iss(result.str());
        std::string name;
        std::string left;
        std::string right;
        iss >> name;
        iss >> left;
        iss >> right;
        PairOfPaths pairOfPaths;
        pairOfPaths.left = left;
        pairOfPaths.right = right;
        this->nodelist[name].push_back(pairOfPaths);
    }
    file.close();
}

const std::string FileReader::getInstructions() {
    return this->instructions;
}

const Nodelist FileReader::getNodelist() {
    return this->nodelist;
}