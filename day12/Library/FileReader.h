//
// Created by sebas on 12.12.2023.
//

#ifndef DAY12_FILEREADER_H
#define DAY12_FILEREADER_H

#include "types.h"
#include <fstream>
#include <sstream>

class FileReader {
public:
    informationLines read(const std::string &path);
};


#endif //DAY12_FILEREADER_H
