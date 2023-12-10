//
// Created by sebas on 10.12.2023.
//

#ifndef DAY10_FILEREADER_H
#define DAY10_FILEREADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "types.h"

class FileReader {
public:
    directionMatrix readFile(std::string fileName);
};

#endif //DAY10_FILEREADER_H
