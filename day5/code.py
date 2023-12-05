import re
import sys

data = open("day5/data.txt", "r").readlines()

class Mapping:
    def __init__(self, destRangeStart, sourceRangeStart, rangeLen):
        self.translationStart = sourceRangeStart
        self.translationEnd = sourceRangeStart + rangeLen - 1
        self.translationFormula = destRangeStart - sourceRangeStart
    
    def __str__(self):
        return f"start: {self.translationStart}, end: {self.translationEnd}, formula: {self.translationFormula}"
    
class SubSet:
    def __init__(self, start, end):
        self.start = start
        self.end = end
    
    def __str__(self):
        return f"start: {self.start}, end: {self.end}"

def createSubSet(start, numberOfElements):
    return [SubSet(start, start + numberOfElements - 1)]

def createMapping(destRangeStart, sourceRangeStart, rangeLen):
    return [Mapping(destRangeStart, sourceRangeStart, rangeLen)]

def get_mapping(lst, element):
    for i, sublist in enumerate(lst):
        if sublist.translationStart <= element <= sublist.translationEnd:
            element += sublist.translationFormula
            return element
    return element

def get_subsets(mappings, subsets):
    result = []
    subsetcopy = subsets.copy()
    while subsetcopy:
        actSubset = subsetcopy.pop(0)
        numberOfResults = len(result)
        for mapping in mappings:
            if actSubset.start >= mapping.translationStart and actSubset.start <= mapping.translationEnd:
                if actSubset.end <= mapping.translationEnd:
                    subset = SubSet(actSubset.start + mapping.translationFormula, actSubset.end + mapping.translationFormula)
                    result.append(subset)
                    break
                else:
                    subset = SubSet(actSubset.start + mapping.translationFormula, mapping.translationEnd + mapping.translationFormula)
                    result.append(subset)
                    actSubset = SubSet(mapping.translationEnd + 1, actSubset.end)
                    subsetcopy.append(actSubset)
                    break
        if numberOfResults == len(result):
            result.append(actSubset)
                    
    return result
    

def evaluateShortestDistance(lst, shortestDistance):
    for element in lst:
        if element.start < shortestDistance:
            shortestDistance = element.start
    return shortestDistance

def printSubsets(subsets):
    for subset in subsets:
        print(subset)

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
listOfSubsets = []
for seed, rng in zip(seeds[::2], seeds[1::2]):
    listOfSubsets += createSubSet(int(seed), int(rng))
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

soil = get_subsets(seedsToSoil, listOfSubsets)
fertilizer = get_subsets(soilToFertilizer, soil)
water = get_subsets(fertilizerToWater, fertilizer)
light = get_subsets(waterToLight, water)
temperature = get_subsets(lightToTemperature, light)
humidity = get_subsets(temperatureToHumidity, temperature)
location = get_subsets(humidityToLocation, humidity)
shortestDistance = evaluateShortestDistance(location, shortestDistance)

print(shortestDistance)