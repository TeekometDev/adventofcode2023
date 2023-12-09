//
// Created by sebas on 09.12.2023.
//

#ifndef DAY9_FILEREADER_H
#define DAY9_FILEREADER_H

#include "types.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class FileReader {
public:
    matrixOfWork readFile(std::string fileName);
};


#endif //DAY9_FILEREADER_H
