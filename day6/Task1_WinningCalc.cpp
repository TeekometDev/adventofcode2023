//
// Created by sebas on 06.12.2023.
//

#include "Task1_WinningCalc.h"

Task1_WinningCalc::Task1_WinningCalc() {}

Task1_WinningCalc::~Task1_WinningCalc() {}

int Task1_WinningCalc::calculatedWinningTraces(std::vector<GAMEDATA> &games) {
    std::cout << "Calculating winning traces" << std::endl;
    std::cout << "Games: " << games.size() << std::endl;
    int winningTraces = 0;
    for (int i = 0; i < games.size(); i++) {
        int wonGames = 0;
        int gameDuration = games[i].duration;
        for (int j = 0; j <= gameDuration; j++) {
            int speed = j;
            int distance = speed * (gameDuration - j);
            if (distance > games[i].distanceToBeat) {
                wonGames++;
            }
        }
        if (winningTraces == 0 && wonGames > 0) {
            winningTraces = 1;
        }
        std::cout << i << ": Won games: " << wonGames << std::endl;
        winningTraces *= wonGames;
    }
    return winningTraces;
}