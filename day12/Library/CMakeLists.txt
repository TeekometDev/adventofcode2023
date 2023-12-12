project(day12libraries)

set(HEADERS types.h)

add_library(fileReader STATIC FileReader.cpp FileReader.h ${HEADERS})
add_library(springCalculator STATIC SpringCalculator.cpp SpringCalculator.h ${HEADERS})