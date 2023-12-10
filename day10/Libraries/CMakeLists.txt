project(day10Libraries)

set(HEADERS types.h)

add_library(fileReader STATIC FileReader.cpp FileReader.h ${HEADERS})
add_library(distanceCalculator STATIC DistanceCalculator.cpp DistanceCalculator.h ${HEADERS})