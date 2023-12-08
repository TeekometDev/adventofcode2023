//
// Created by sebas on 08.12.2023.
//

#ifndef DAY8_PATHFINDER_H
#define DAY8_PATHFINDER_H

#include "FileReader.h"
#include <numeric>

class Pathfinder {
public:
    int findPath(std::string instructions, Nodelist nodelist);
    long long findGhostPath(std::string instructions, Nodelist nodelist);
protected:
    const std::string START_VALUE = "AAA";
    const std::string END_VALUE = "ZZZ";
    const char START_CHAR = 'A';
    const char END_CHAR = 'Z';
private:
    std::vector<std::string> getStartPaths(Nodelist &nodelist);
};


#endif //DAY8_PATHFINDER_H
