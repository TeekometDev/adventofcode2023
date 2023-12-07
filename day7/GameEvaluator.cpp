//
// Created by sebas on 07.12.2023.
//

#include "GameEvaluator.h"

int GameEvaluator::evaluateGames(const ListOfGames &games) {
    int sum = 0;
    ListOfGames rankedGames;
    rankGames(games, rankedGames);
    for (int i = 0; i < games.size(); i++) {
        sum += rankedGames[i].bid * (i + 1);
    }
    return sum;
}

void GameEvaluator::rankGames(const ListOfGames &games, ListOfGames &rankedGames) {
    ListOfGames fiveOfAKind;
    ListOfGames fourOfAKind;
    ListOfGames fullHouse;
    ListOfGames threeOfAKind;
    ListOfGames twoPairs;
    ListOfGames onePair;
    ListOfGames highCard;

    for (auto &game : games) {
        std::vector<char> gameCards = game.cards;
        std::sort(gameCards.begin(), gameCards.end());
        if (gameCards[0] == gameCards[4]) {
            fiveOfAKind.push_back(game);
        } else if (gameCards[0] == gameCards[3] || gameCards[1] == gameCards[4]) {
            fourOfAKind.push_back(game);
        } else if ((gameCards[0] == gameCards[2] && gameCards[3] == gameCards[4]) ||
                   (gameCards[0] == gameCards[1] && gameCards[2] == gameCards[4])) {
            fullHouse.push_back(game);
        } else if (gameCards[0] == gameCards[2] || gameCards[1] == gameCards[3] || gameCards[2] == gameCards[4]) {
            threeOfAKind.push_back(game);
        } else if ((gameCards[0] == gameCards[1] && gameCards[2] == gameCards[3]) ||
                   (gameCards[0] == gameCards[1] && gameCards[3] == gameCards[4]) ||
                   (gameCards[1] == gameCards[2] && gameCards[3] == gameCards[4])) {
            twoPairs.push_back(game);
        } else if (gameCards[0] == gameCards[1] || gameCards[1] == gameCards[2] || gameCards[2] == gameCards[3] ||
                   gameCards[3] == gameCards[4]) {
            onePair.push_back(game);
        } else {
            highCard.push_back(game);
        }
    }

    std::sort(fiveOfAKind.begin(), fiveOfAKind.end(), compareHands);
    std::sort(fourOfAKind.begin(), fourOfAKind.end(), compareHands);
    std::sort(fullHouse.begin(), fullHouse.end(), compareHands);
    std::sort(threeOfAKind.begin(), threeOfAKind.end(), compareHands);
    std::sort(twoPairs.begin(), twoPairs.end(), compareHands);
    std::sort(onePair.begin(), onePair.end(), compareHands);
    std::sort(highCard.begin(), highCard.end(), compareHands);

    rankedGames.insert(rankedGames.end(), highCard.begin(), highCard.end());
    rankedGames.insert(rankedGames.end(), onePair.begin(), onePair.end());
    rankedGames.insert(rankedGames.end(), twoPairs.begin(), twoPairs.end());
    rankedGames.insert(rankedGames.end(), threeOfAKind.begin(), threeOfAKind.end());
    rankedGames.insert(rankedGames.end(), fullHouse.begin(), fullHouse.end());
    rankedGames.insert(rankedGames.end(), fourOfAKind.begin(), fourOfAKind.end());
    rankedGames.insert(rankedGames.end(), fiveOfAKind.begin(), fiveOfAKind.end());
}

bool GameEvaluator::compareHands(const Game &game1, const Game &game2) {
    std::vector<char> game1Cards = game1.cards;
    std::vector<char> game2Cards = game2.cards;
    if (game1Cards[0] == game2Cards[0]) {
        if (game1Cards[1] == game2Cards[1]) {
            if (game1Cards[2] == game2Cards[2]) {
                if (game1Cards[3] == game2Cards[3]) {
                    return getCharValue(game1Cards[4]) < getCharValue(game2Cards[4]);
                } else {
                    return getCharValue(game1Cards[3]) < getCharValue(game2Cards[3]);
                }
            } else {
                return getCharValue(game1Cards[2]) < getCharValue(game2Cards[2]);
            }
        } else {
            return getCharValue(game1Cards[1]) < getCharValue(game2Cards[1]);
        }
    } else {
        return getCharValue(game1Cards[0]) < getCharValue(game2Cards[0]);
    }
}

int GameEvaluator::getCharValue(const char &character) {
    switch (character) {
        case 'T':
            return 10;
        case 'J':
            return 11;
        case 'Q':
            return 12;
        case 'K':
            return 13;
        case 'A':
            return 14;
        default:
            return character - '0';
    }
}


void JokerGameEvaluator::rankGames(const ListOfGames &games, ListOfGames &rankedGames) {
    ListOfGames fiveOfAKind;
    ListOfGames fourOfAKind;
    ListOfGames fullHouse;
    ListOfGames threeOfAKind;
    ListOfGames twoPairs;
    ListOfGames onePair;
    ListOfGames highCard;

    for (auto &game: games) {
        std::vector<char> gameCards = game.cards;
        gameCards.erase(std::remove(gameCards.begin(), gameCards.end(), 'J'), gameCards.end());
        std::sort(gameCards.begin(), gameCards.end());
        if (gameCards.size() == 0 || gameCards.size() == 1) {
            fiveOfAKind.push_back(game);
        } else if (gameCards.size() == 2) {
            if (gameCards[0] == gameCards[1]) {
                fiveOfAKind.push_back(game);
            } else {
                fourOfAKind.push_back(game);
            }
        } else if (gameCards.size() == 3) {
            if (gameCards[0] == gameCards[2]) {
                fiveOfAKind.push_back(game);
            } else if (gameCards[0] == gameCards[1] || gameCards[1] == gameCards[2]) {
                fourOfAKind.push_back(game);
            } else {
                threeOfAKind.push_back(game);
            }
        } else if (gameCards.size() == 4) {
            if(gameCards[0] == gameCards[3]) {
                fiveOfAKind.push_back(game);
            } else if (gameCards[0] == gameCards[2] || gameCards[1] == gameCards[3]) {
                fourOfAKind.push_back(game);
            } else if (gameCards[0] == gameCards[1] && gameCards[2] == gameCards[3]) {
                fullHouse.push_back(game);
            } else if (gameCards[0] == gameCards[1] || gameCards[1] == gameCards[2] || gameCards[2] == gameCards[3]) {
                threeOfAKind.push_back(game);
            } else {
                onePair.push_back(game);
            }
        } else {
            if (gameCards[0] == gameCards[4]) {
                fiveOfAKind.push_back(game);
            } else if (gameCards[0] == gameCards[3] || gameCards[1] == gameCards[4]) {
                fourOfAKind.push_back(game);
            } else if ((gameCards[0] == gameCards[2] && gameCards[3] == gameCards[4]) ||
                       (gameCards[0] == gameCards[1] && gameCards[2] == gameCards[4])) {
                fullHouse.push_back(game);
            } else if (gameCards[0] == gameCards[2] || gameCards[1] == gameCards[3] || gameCards[2] == gameCards[4]) {
                threeOfAKind.push_back(game);
            } else if ((gameCards[0] == gameCards[1] && gameCards[2] == gameCards[3]) ||
                       (gameCards[0] == gameCards[1] && gameCards[3] == gameCards[4]) ||
                       (gameCards[1] == gameCards[2] && gameCards[3] == gameCards[4])) {
                twoPairs.push_back(game);
            } else if (gameCards[0] == gameCards[1] || gameCards[1] == gameCards[2] || gameCards[2] == gameCards[3] ||
                       gameCards[3] == gameCards[4]) {
                onePair.push_back(game);
            } else {
                highCard.push_back(game);
            }
        }
    }

    std::sort(fiveOfAKind.begin(), fiveOfAKind.end(), compareHands);
    std::sort(fourOfAKind.begin(), fourOfAKind.end(), compareHands);
    std::sort(fullHouse.begin(), fullHouse.end(), compareHands);
    std::sort(threeOfAKind.begin(), threeOfAKind.end(), compareHands);
    std::sort(twoPairs.begin(), twoPairs.end(), compareHands);
    std::sort(onePair.begin(), onePair.end(), compareHands);
    std::sort(highCard.begin(), highCard.end(), compareHands);

    rankedGames.insert(rankedGames.end(), highCard.begin(), highCard.end());
    rankedGames.insert(rankedGames.end(), onePair.begin(), onePair.end());
    rankedGames.insert(rankedGames.end(), twoPairs.begin(), twoPairs.end());
    rankedGames.insert(rankedGames.end(), threeOfAKind.begin(), threeOfAKind.end());
    rankedGames.insert(rankedGames.end(), fullHouse.begin(), fullHouse.end());
    rankedGames.insert(rankedGames.end(), fourOfAKind.begin(), fourOfAKind.end());
    rankedGames.insert(rankedGames.end(), fiveOfAKind.begin(), fiveOfAKind.end());
}

int JokerGameEvaluator::getCharValue(const char &character) {
    switch (character) {
        case 'T':
            return 10;
        case 'J':
            return 0;
        case 'Q':
            return 12;
        case 'K':
            return 13;
        case 'A':
            return 14;
        default:
            return character - '0';
    }
}

bool JokerGameEvaluator::compareHands(const Game &game1, const Game &game2) {
    std::vector<char> game1Cards = game1.cards;
    std::vector<char> game2Cards = game2.cards;
    if (game1Cards[0] == game2Cards[0]) {
        if (game1Cards[1] == game2Cards[1]) {
            if (game1Cards[2] == game2Cards[2]) {
                if (game1Cards[3] == game2Cards[3]) {
                    return getCharValue(game1Cards[4]) < getCharValue(game2Cards[4]);
                } else {
                    return getCharValue(game1Cards[3]) < getCharValue(game2Cards[3]);
                }
            } else {
                return getCharValue(game1Cards[2]) < getCharValue(game2Cards[2]);
            }
        } else {
            return getCharValue(game1Cards[1]) < getCharValue(game2Cards[1]);
        }
    } else {
        return getCharValue(game1Cards[0]) < getCharValue(game2Cards[0]);
    }
}