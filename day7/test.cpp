//
// Created by sebas on 07.12.2023.
//

#include "FileReader.h"
#include <iostream>
#include "GameEvaluator.h"

int main() {
    FileReader fileReader;
    ListOfGames games = fileReader.readCardsFromFile("test.txt");
    GameEvaluator evaluator;
    int ranks = evaluator.evaluateGames(games);
    std::cout << ranks << std::endl;
    if (ranks == 6440) {
        std::cout << "Test 1 passed!" << std::endl;
    } else {
        std::cerr << "Test 1 failed!" << std::endl;
        return 1;
    }

    JokerGameEvaluator jokerGameEvaluator;
    ranks = jokerGameEvaluator.evaluateGames(games);
    std::cout << ranks << std::endl;
    if (ranks == 5905) {
        std::cout << "Test 2 passed!" << std::endl;
    } else {
        std::cerr << "Test 2 failed!" << std::endl;
        return 1;
    }
    return 0;
}