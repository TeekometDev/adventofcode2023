//
// Created by sebas on 07.12.2023.
//

#ifndef DAY7_GAMEEVALUATOR_H
#define DAY7_GAMEEVALUATOR_H

#include "FileReader.h"
#include <algorithm>

class GameEvaluator {
public:
    int evaluateGames(const ListOfGames &games);
private:
    virtual void rankGames(const ListOfGames &games, ListOfGames &rankedGames);
    static int getCharValue(const char &character);
    static bool compareHands(const Game &game1, const Game &game2);
};

class JokerGameEvaluator : public GameEvaluator {
private:
    void rankGames(const ListOfGames &games, ListOfGames &rankedGames) override;
    static int getCharValue(const char &character);
    static int getNumberOfJokers(const std::vector<char> &cards);
    static bool compareHands(const Game &game1, const Game &game2);
};


#endif //DAY7_GAMEEVALUATOR_H
