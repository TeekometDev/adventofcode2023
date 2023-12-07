//
// Created by sebas on 07.12.2023.
//

#ifndef DAY7_FILEREADER_H
#define DAY7_FILEREADER_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <array>

typedef struct {
    std::vector<char> cards;
    int bid;
} Game;

using ListOfGames = std::vector<Game>;

class FileReader {
public:
    static ListOfGames readCardsFromFile(const std::string &fileName);
private:
    static int getCardNumber(const char &character);
};


#endif //DAY7_FILEREADER_H
