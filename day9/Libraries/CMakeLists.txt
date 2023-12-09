project(Day9Libraries)

set(HEADERS types.h)

add_library(fileReader STATIC FileReader.cpp FileReader.h ${HEADERS})
add_library(calculator STATIC ExtrapolationCalculator.cpp ExtrapolationCalculator.h ${HEADERS})