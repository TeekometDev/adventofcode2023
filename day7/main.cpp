//
// Created by sebas on 07.12.2023.
//

#include "FileReader.h"
#include <iostream>
#include "GameEvaluator.h"

int main() {
    FileReader fileReader;
    ListOfGames games = fileReader.readCardsFromFile("data.txt");
    GameEvaluator evaluator;
    int ranks = evaluator.evaluateGames(games);
    std::cout << "Task1: " << ranks << std::endl;
    JokerGameEvaluator jokerGameEvaluator;
    ranks = jokerGameEvaluator.evaluateGames(games);
    std::cout << "Task2: " << ranks << std::endl;
    return 0;
}