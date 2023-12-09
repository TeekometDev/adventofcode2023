//
// Created by sebas on 09.12.2023.
//

#ifndef DAY9_EXTRAPOLATIONCALCULATOR_H
#define DAY9_EXTRAPOLATIONCALCULATOR_H

#include "types.h"
#include <iostream>

class ExtrapolationCalculator {
public:
    int calculate(matrixOfWork matrix);
    int getBackwardValue();
private:
    static bool isLineFinished(calculationLine &line);
    static calculationLine calculateNextLine(calculationLine &line);
    static int calculateBackwards(calculatedLines &lines);
    static int calculateBackwardsLine(calculatedLines &lines);
    int backwardValue = 0;
};


#endif //DAY9_EXTRAPOLATIONCALCULATOR_H
