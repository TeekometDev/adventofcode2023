//
// Created by sebas on 06.12.2023.
//

#ifndef ADVENTOFCODE2023_GATHERINGDATA_H
#define ADVENTOFCODE2023_GATHERINGDATA_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <regex>

typedef struct {
    long long duration;
    long long distanceToBeat;
} GAMEDATA;

class GatheringData {
public:
    GatheringData(std::string path);
    ~GatheringData();
    std::vector<GAMEDATA> currentGame;
private:
    std::vector<GAMEDATA> generateGames(std::string durations, std::string distances);
};


#endif //ADVENTOFCODE2023_GATHERINGDATA_H
