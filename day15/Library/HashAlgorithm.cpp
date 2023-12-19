//
// Created by sebas on 19.12.2023.
//

#include "HashAlgorithm.h"

uint32_t HashAlgorithm::calculateHashValue(stringlist &input) {
    uint32_t hashValue = 0;
    for (const std::string &line : input) {
        hashValue += calculateHashValueForLine(line);
    }
    return hashValue;
}

int HashAlgorithm::calculateHashValueForLine(const std::string &line) {
    int hashValue = 0;
    for (const char &character : line) {
        hashValue += calculateHashValueForCharacter(character);
        hashValue *= 17;
        hashValue %= 256;
    }
    return hashValue;
}

int HashAlgorithm::calculateHashValueForCharacter(const char &character) {
    return character;
}