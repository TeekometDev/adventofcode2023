//
// Created by sebas on 09.12.2023.
//

#include "ExtrapolationCalculator.h"

int ExtrapolationCalculator::calculate(matrixOfWork matrix) {
    int result = 0;
    int backwardedValue = 0;
    for (int i = 0; i < matrix.size(); i++) {
        calculatedLines lines = matrix[i];
        calculationLine actLine = lines[0];
        do {
            lines.push_back(calculateNextLine(actLine));
            actLine = lines[lines.size() - 1];
        } while (!isLineFinished(actLine));
        result += calculateBackwards(lines);
        backwardedValue += calculateBackwardsLine(lines);
    }
    backwardValue = backwardedValue;
    return result;
}

bool ExtrapolationCalculator::isLineFinished(calculationLine &line) {
    for (int i = 0; i < line.size(); ++i) {
        if (line[i] != 0) {
            return false;
        }
    }
    return true;
}

calculationLine ExtrapolationCalculator::calculateNextLine(calculationLine &line) {
    calculationLine result;
    for (int i = 1; i < line.size(); i++) {
        result.push_back(line[i] - line[i-1]);
    }
    return result;
}

int ExtrapolationCalculator::calculateBackwards(calculatedLines &lines) {
    // Adding Zero to last line
    calculationLine baseLine = lines[lines.size() - 1];
    baseLine.push_back(0);
    for (int i = lines.size() - 2; i >= 0; i--) {
        int sumValue = baseLine[baseLine.size() - 1];
        baseLine = lines[i];
        baseLine.push_back(baseLine[baseLine.size() - 1] + sumValue);
    }
    int result = baseLine[baseLine.size() - 1];
    return result;
}

int ExtrapolationCalculator::calculateBackwardsLine(calculatedLines &lines) {
    int additionValue = 0;
    for (int i = lines.size() - 2; i >= 0; i--) {
        additionValue = lines[i][0] - additionValue;
    }
    return additionValue;
}

int ExtrapolationCalculator::getBackwardValue() {
    return backwardValue;
}
