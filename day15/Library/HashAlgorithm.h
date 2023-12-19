//
// Created by sebas on 19.12.2023.
//

#ifndef DAY15_HASHALGORITHM_H
#define DAY15_HASHALGORITHM_H

#include "types.h"

class HashAlgorithm {
public:
    uint32_t calculateHashValue(stringlist &input);
    int calculateHashValueForLine(const std::string &line);
    int calculateHashValueForCharacter(const char &character);
};


#endif //DAY15_HASHALGORITHM_H
