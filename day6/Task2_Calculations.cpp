//
// Created by sebas on 06.12.2023.
//

#include "Task2_Calculations.h"

Task2_Calculations::Task2_Calculations() {

}

Task2_Calculations::~Task2_Calculations() {

}

int Task2_Calculations::calculateNumberOfPossibilities(std::vector<GAMEDATA>& games) {
    GAMEDATA merged = mergeNumbers(games);
    int wonGames = 0;
    long long gameDuration = merged.duration;
    for (long long j = 0; j <= gameDuration; j++) {
        long long speed = j;
        long long distance = speed * (gameDuration - j);
        if (distance > merged.distanceToBeat) {
            wonGames++;
        }
    }
    return wonGames;
}

GAMEDATA Task2_Calculations::mergeNumbers(std::vector<GAMEDATA>& games) {
    GAMEDATA result;
    std::string durations = "";
    std::string distances = "";
    for(int i = 0; i < games.size(); i++) {
        durations += std::to_string(games[i].duration);
        distances += std::to_string(games[i].distanceToBeat);
    }
    std::cout << "Merged duration: " << durations << std::endl;
    result.duration = std::stoll(durations);
    std::cout << "Merged distance: " << distances << std::endl;
    result.distanceToBeat = std::stoll(distances);
    std::cout << "Merged duration: " << result.duration << std::endl;
    std::cout << "Merged distance: " << result.distanceToBeat << std::endl;
    return result;
}