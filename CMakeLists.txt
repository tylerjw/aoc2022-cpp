cmake_minimum_required(VERSION 3.22)
project(aoc2022-cpp CXX)

find_package(range-v3 REQUIRED)

add_executable(aoc2022-cpp src/aoc2022-cpp.cpp src/main.cpp)
target_link_libraries(aoc2022-cpp range-v3::range-v3)
