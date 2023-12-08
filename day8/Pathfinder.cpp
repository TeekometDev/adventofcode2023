//
// Created by sebas on 08.12.2023.
//

#include "Pathfinder.h"
#include <iostream>

int Pathfinder::findPath(std::string instructions, Nodelist nodelist) {
    int result = 0;
    const int MAX_DEPTH = instructions.length();
    std::string current = START_VALUE;
    while (current != END_VALUE) {
        PairOfPaths ways = nodelist[current][0];
        current = instructions[result % MAX_DEPTH] == 'L' ? ways.left : ways.right;
        result++;
    }
    return result;
}

long long Pathfinder::findGhostPath(std::string instructions, Nodelist nodelist) {
    long long result = 1;
    const int MAX_DEPTH = instructions.length();
    std::vector<std::string> paths = getStartPaths(nodelist);
    std::vector<long> pathLengths;
    for (auto path : paths) {
        int pathLength = 0;
        std::string current = path;
        while (current[2] != END_CHAR) {
            PairOfPaths ways = nodelist[current][0];
            current = instructions[pathLength % MAX_DEPTH] == 'L' ? ways.left : ways.right;
            pathLength++;
        }
        pathLengths.push_back(pathLength);
    }
    for (int value : pathLengths) {
        result = std::lcm(result, value);
    }

    return result;
}

std::vector<std::string> Pathfinder::getStartPaths(Nodelist &nodelist) {
    std::vector<std::string> result;
    for (auto node : nodelist) {
        if (node.first[2] == START_CHAR) {
            result.push_back(node.first);
        }
    }
    return result;
}
