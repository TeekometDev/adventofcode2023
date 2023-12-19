//
// Created by sebas on 19.12.2023.
//

#ifndef DAY15_HASHMAP_H
#define DAY15_HASHMAP_H

#include "types.h"
#include "HashAlgorithm.h"

class HashMap {
public:
    HashMap();
    uint32_t calculateFocalLength(stringlist &input);
private:
    HashAlgorithm* hashAlgorithm;
};


#endif //DAY15_HASHMAP_H
