project(day12libraries)

set(HEADERS types.h)

add_library(fileReader STATIC FileReader.cpp FileReader.h ${HEADERS})
add_library(hashAlgorithm STATIC HashAlgorithm.cpp HashAlgorithm.h ${HEADERS})
add_library(hashMap STATIC HashMap.cpp HashMap.h ${HEADERS})
