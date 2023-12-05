import re
import sys

data = open("day5/data.txt", "r").readlines()

class Mapping:
    def __init__(self, destRangeStart, sourceRangeStart, rangeLen):
        self.translationStart = sourceRangeStart
        self.translationEnd = sourceRangeStart + rangeLen - 1
        self.translationFormula = destRangeStart - sourceRangeStart

def createMapping(destRangeStart, sourceRangeStart, rangeLen):
    return [Mapping(destRangeStart, sourceRangeStart, rangeLen)]

def get_mapping(lst, element):
    for i, sublist in enumerate(lst):
        if sublist.translationStart <= element <= sublist.translationEnd:
            element += sublist.translationFormula
            return element
    return element

seeds = []
seedsToSoil = []
soilToFertilizer = []
fertilizerToWater = []
waterToLight = []
lightToTemperature = []
temperatureToHumidity = []
humidityToLocation = []

startLine = data.pop(0)
startLine = re.sub("seeds: ", '', startLine)
startLine = re.sub("\n", '', startLine)
seeds = startLine.split(" ")
seeds = [int(i) for i in seeds]
data.pop(0)
data.pop(0)

while data[1] != "soil-to-fertilizer map:\n":
    actLine = data.pop(0)
    actLine = re.sub("\n", '', actLine)
    impValues = actLine.split(" ")
    seedsToSoil += createMapping(int(impValues[0]), int(impValues[1]), int(impValues[2]))

data.pop(0)
data.pop(0)

while data[1] != "fertilizer-to-water map:\n":
    actLine = data.pop(0)
    actLine = re.sub("\n", '', actLine)
    impValues = actLine.split(" ")
    soilToFertilizer += createMapping(int(impValues[0]), int(impValues[1]), int(impValues[2]))

data.pop(0)
data.pop(0)

while data[1] != "water-to-light map:\n": 
    actLine = data.pop(0)
    actLine = re.sub("\n", '', actLine)
    impValues = actLine.split(" ")
    fertilizerToWater += createMapping(int(impValues[0]), int(impValues[1]), int(impValues[2]))

data.pop(0)
data.pop(0)

while data[1] != "light-to-temperature map:\n":
    actLine = data.pop(0)
    actLine = re.sub("\n", '', actLine)
    impValues = actLine.split(" ")
    waterToLight += createMapping(int(impValues[0]), int(impValues[1]), int(impValues[2]))

data.pop(0)
data.pop(0)

while data[1] != "temperature-to-humidity map:\n":
    actLine = data.pop(0)
    actLine = re.sub("\n", '', actLine)
    impValues = actLine.split(" ")
    lightToTemperature += createMapping(int(impValues[0]), int(impValues[1]), int(impValues[2]))

data.pop(0)
data.pop(0)

while data[1] != "humidity-to-location map:\n":
    actLine = data.pop(0)
    actLine = re.sub("\n", '', actLine)
    impValues = actLine.split(" ")
    temperatureToHumidity += createMapping(int(impValues[0]), int(impValues[1]), int(impValues[2]))

data.pop(0)
data.pop(0)

while data:
    actLine = data.pop(0)
    actLine = re.sub("\n", '', actLine)
    impValues = actLine.split(" ")
    humidityToLocation += createMapping(int(impValues[0]), int(impValues[1]), int(impValues[2]))

shortestDistance = sys.maxsize


for seeds, rng in zip(seeds[::2], seeds[1::2]):
    for i in range(rng):
        soil = get_mapping(seedsToSoil, seeds + i)
        fertilizer = get_mapping(soilToFertilizer, soil)
        water = get_mapping(fertilizerToWater, fertilizer)
        light = get_mapping(waterToLight, water)
        temperature = get_mapping(lightToTemperature, light)
        humidity = get_mapping(temperatureToHumidity, temperature)
        location = get_mapping(humidityToLocation, humidity)
        if location < shortestDistance:
            shortestDistance = location

print(shortestDistance)