//
// Created by sebas on 11.12.2023.
//

#ifndef DAY11_FILEREADER_H
#define DAY11_FILEREADER_H

#include "types.h"
#include <string>
#include <fstream>

class FileReader {
public:
    spaceGrid read(std::string filename);
};


#endif //DAY11_FILEREADER_H
