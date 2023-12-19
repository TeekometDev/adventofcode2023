//
// Created by sebas on 19.12.2023.
//

#include "HashMap.h"

HashMap::HashMap() {
    hashAlgorithm = new HashAlgorithm();
}

uint32_t HashMap::calculateFocalLength(stringlist &input) {
    boxlist boxes;
    boxes.resize(256);
    uint32_t focalLength = 0;
    for (auto &line : input) {
        int commandPosition = line.find("-");
        if (commandPosition >= 0) {
            // remove lens
            std::string lensAddress = line.substr(0,commandPosition);
            int addressHash = hashAlgorithm->calculateHashValueForLine(lensAddress);
            box& currentBox = boxes[addressHash];
            for (int i = 0; i < currentBox.size(); i++) {
                if (currentBox[i].first == lensAddress) {
                    currentBox.erase(currentBox.begin() + i, currentBox.begin() + i + 1);
                    break;
                }
            }
        } else {
            // add lens
            commandPosition = line.find("=");
            std::string lensAddress = line.substr(0, commandPosition);
            int lensFocalLength = line[commandPosition + 1] - '0';
            int addressHash = hashAlgorithm->calculateHashValueForLine(lensAddress);
            bool replacedLens = false;
            box& currentBox = boxes[addressHash];
            for (int i = 0; i < currentBox.size(); i++) {
                if (currentBox[i].first == lensAddress) {
                    currentBox[i].second = lensFocalLength;
                    replacedLens = true;
                    break;
                }
            }
            if (!replacedLens) {
                currentBox.push_back(std::make_pair(lensAddress, lensFocalLength));
            }
        }
    }
    for (int i = 0; i < boxes.size(); i++) {
        box& box = boxes[i];
        for (int j = 0; j < box.size(); j++) {
            focalLength += box[j].second * (i + 1) * (j + 1);
        }
    }
    return focalLength;
}