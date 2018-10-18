project(sk8bmsCore)

file(GLOB_RECURSE CORE_SOURCES *.h *.cpp)

add_library(sk8bmsCore ${CORE_SOURCES})