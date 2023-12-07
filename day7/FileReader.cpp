//
// Created by sebas on 07.12.2023.
//

#include "FileReader.h"

ListOfGames FileReader::readCardsFromFile(const std::string &fileName) {
    std::ifstream file(fileName);
    std::string line;
    ListOfGames games;
    while (std::getline(file, line)) {
        Game game;
        std::istringstream iss(line);
        std::string output;
        iss >> output;
        for (int i = 0; i < 5; i++) {
            game.cards.push_back(output[i]);
        }
        iss >> output;
        int bid = std::stoi(output);
        game.bid = bid;
        games.push_back(game);
    }
    return games;
}

