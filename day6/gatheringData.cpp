//
// Created by sebas on 06.12.2023.
//

#include "gatheringData.h"

std::vector<int> extractNumbers(std::string line) {
    std::vector<int> numbers;
    std::stringstream ss;
    ss << line;
    int temp;
    while (!ss.eof()) {
        ss >> temp;
        numbers.push_back(temp);
    }
    return numbers;
}

GatheringData::GatheringData(std::string path) {
    std::fstream file;
    file.open(path);
    std::cout << "Reading file" << std::endl;
    if (file.is_open()) {
        std::string gameDuration;
        std::string distanceToBeat;
        std::getline(file, gameDuration);
        std::getline(file, distanceToBeat);
        file.close();
        this->currentGame = this->generateGames(gameDuration, distanceToBeat);
    } else {
        std::cerr << "Error opening file" << std::endl;
    }
}

GatheringData::~GatheringData() {
    this->currentGame.clear();
}

std::vector<GAMEDATA> GatheringData::generateGames(std::string durations, std::string distances) {
    std::vector<GAMEDATA> games;
    durations = std::regex_replace(durations, std::regex("Time:"), "");
    durations = std::regex_replace(durations, std::regex("\n"), "");
    distances = std::regex_replace(distances, std::regex("Distance:"), "");
    distances = std::regex_replace(distances, std::regex("\n"), "");
    std::vector<int> duration = extractNumbers(durations);
    std::vector<int> distance = extractNumbers(distances);
    for (int i = 0; i < duration.size(); i++) {
        GAMEDATA game;
        game.duration = duration[i];
        game.distanceToBeat = distance[i];
        games.push_back(game);
    }
    return games;
}
