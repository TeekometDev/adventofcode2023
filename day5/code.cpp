//
// Created by sebas on 05.12.2023.
//

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <sstream>
#include <vector>
#include <limits>

enum STATE {
    SEEDS,
    SEEDTOSOIL,
    SOILTOFERTILIZER,
    FERTILIZERTOWATER,
    WATERTOLIGHT,
    LIGHTTOTEMPERATURE,
    TEMPERATURETOHUMIDITY,
    HUMIDITYTOLOCATION,
    EMPTY
};

class Mapping {
public:
    Mapping(int destRangeStart, int sourceRangeStart, int rangeLen) : translationStart(sourceRangeStart), translationEnd(sourceRangeStart + rangeLen - 1), translationFormula(destRangeStart - sourceRangeStart) {}
    int translationStart;
    int translationEnd;
    int translationFormula;
};

std::vector<int> extractNumbers(std::string line) {
    std::vector<int> numbers;
    std::stringstream ss;
    ss << line;
    int temp;
    while (!ss.eof()) {
        ss >> temp;
        numbers.push_back(temp);
    }
    return numbers;
}

int main() {
    std::ifstream file;
    file.open("day5/test.txt");

    if (!file.is_open()) {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }

    std::string line;
    std::regex pattern("seeds: ");
    std::regex newlinePattern("\n");
    STATE state = SEEDS;
    std::vector<int> seeds;
    std::vector<Mapping> seedToSoil;
    std::vector<Mapping> soilToFertilizer;
    std::vector<Mapping> fertilizerToWater;
    std::vector<Mapping> waterToLight;
    std::vector<Mapping> lightToTemperature;
    std::vector<Mapping> temperatureToHumidity;
    std::vector<Mapping> humidityToLocation;

    while(std::getline(file, line)) {
        line = std::regex_replace(line, newlinePattern, "");
        switch (state) {
            case SEEDS:
                line = std::regex_replace(line, pattern, "");
                if (line == "seed-to-soil map:") {
                    state = SEEDTOSOIL;
                    break;
                } else if (line != "") {
                    seeds = extractNumbers(line);
                }
                break;
            case SEEDTOSOIL:
                if (line == "soil-to-fertilizer map:") {
                    state = SOILTOFERTILIZER;
                    break;
                } else if (line != "") {
                    std::vector<int> numbers = extractNumbers(line);
                    seedToSoil.push_back(Mapping(numbers[0], numbers[1], numbers[2]));
                }
                break;
            case SOILTOFERTILIZER:
                if (line == "fertilizer-to-water map:") {
                    state = FERTILIZERTOWATER;
                    break;
                } else if (line != "") {
                    std::vector<int> numbers = extractNumbers(line);
                    soilToFertilizer.push_back(Mapping(numbers[0], numbers[1], numbers[2]));
                }
                break;
            case FERTILIZERTOWATER:
                if (line == "water-to-light map:") {
                    state = WATERTOLIGHT;
                    break;
                } else if (line != "") {
                    std::vector<int> numbers = extractNumbers(line);
                    fertilizerToWater.push_back(Mapping(numbers[0], numbers[1], numbers[2]));
                }
                break;
            case WATERTOLIGHT:
                if (line == "light-to-temperature map:") {
                    state = LIGHTTOTEMPERATURE;
                    break;
                } else if (line != "") {
                    std::vector<int> numbers = extractNumbers(line);
                    waterToLight.push_back(Mapping(numbers[0], numbers[1], numbers[2]));
                }
                break;
            case LIGHTTOTEMPERATURE:
                if (line == "temperature-to-humidity map:") {
                    state = TEMPERATURETOHUMIDITY;
                    break;
                } else if (line != "") {
                    std::vector<int> numbers = extractNumbers(line);
                    lightToTemperature.push_back(Mapping(numbers[0], numbers[1], numbers[2]));
                }
                break;
            case TEMPERATURETOHUMIDITY:
                if (line == "humidity-to-location map:") {
                    state = HUMIDITYTOLOCATION;
                    break;
                } else if (line != "") {
                    std::vector<int> numbers = extractNumbers(line);
                    temperatureToHumidity.push_back(Mapping(numbers[0], numbers[1], numbers[2]));
                }
                break;
            case HUMIDITYTOLOCATION:
                if (line == "humidity to location") {
                    state = EMPTY;
                } else if (line != "") {
                    std::vector<int> numbers = extractNumbers(line);
                    humidityToLocation.push_back(Mapping(numbers[0], numbers[1], numbers[2]));
                }
                break;
            case EMPTY:
                break;
        }
    }
    file.close();
    unsigned int len = std::numeric_limits<unsigned int>::max();
    for (int i = 0; i < seeds.size(); i++) {
        int seed = seeds[i];
        for (int j = 0; j < seedToSoil.size(); j++) {
            if (seed >= seedToSoil[j].translationStart && seed <= seedToSoil[j].translationEnd) {
                seed = seed + seedToSoil[j].translationFormula;
                break;
            }
        }
        for (int j = 0; j < soilToFertilizer.size(); j++) {
            if (seed >= soilToFertilizer[j].translationStart && seed <= soilToFertilizer[j].translationEnd) {
                seed = seed + soilToFertilizer[j].translationFormula;
                break;
            }
        }
        for (int j = 0; j < fertilizerToWater.size(); j++) {
            if (seed >= fertilizerToWater[j].translationStart && seed <= fertilizerToWater[j].translationEnd) {
                seed = seed + fertilizerToWater[j].translationFormula;
                break;
            }
        }
        for (int j = 0; j < waterToLight.size(); j++) {
            if (seed >= waterToLight[j].translationStart && seed <= waterToLight[j].translationEnd) {
                seed = seed + waterToLight[j].translationFormula;
                break;
            }
        }
        for (int j = 0; j < lightToTemperature.size(); j++) {
            if (seed >= lightToTemperature[j].translationStart && seed <= lightToTemperature[j].translationEnd) {
                seed = seed + lightToTemperature[j].translationFormula;
                break;
            }
        }
        for (int j = 0; j < temperatureToHumidity.size(); j++) {
            if (seed >= temperatureToHumidity[j].translationStart && seed <= temperatureToHumidity[j].translationEnd) {
                seed = seed + temperatureToHumidity[j].translationFormula;
                break;
            }
        }
        for (int j = 0; j < humidityToLocation.size(); j++) {
            if (seed >= humidityToLocation[j].translationStart && seed <= humidityToLocation[j].translationEnd) {
                seed = seed + humidityToLocation[j].translationFormula;
                break;
            }
        }
        if (seed < len) {
            len = seed;
        }
    }

    std::cout << len << std::endl;

    return 0;
}
