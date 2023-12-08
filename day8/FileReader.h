//
// Created by sebas on 08.12.2023.
//

#ifndef DAY8_FILEREADER_H
#define DAY8_FILEREADER_H

#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <regex>

typedef struct {
    std::string left;
    std::string right;
} PairOfPaths;

using Nodelist = std::map<std::string, std::vector<PairOfPaths>>;

class FileReader {
public:
    void readPathsFromFile(const std::string &fileName);
    const Nodelist getNodelist();
    const std::string getInstructions();
private:
    Nodelist nodelist;
    std::string instructions;
};


#endif //DAY8_FILEREADER_H
