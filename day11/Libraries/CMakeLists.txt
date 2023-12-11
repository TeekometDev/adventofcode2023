project(day11Libraries)

set(HEADERS types.h)

add_library(fileReader STATIC FileReader.cpp FileReader.h ${HEADERS})
add_library(distanceCalculator STATIC SpaceDistanceCalculator.cpp SpaceDistanceCalculator.h ${HEADERS})