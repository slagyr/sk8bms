cmake_minimum_required(VERSION 3.2.2)
project(sk8bms)

add_definitions(-std=gnu++0x)

include_directories(core)

add_subdirectory(core)
add_subdirectory(test)

target_link_libraries(sk8bmsCore)