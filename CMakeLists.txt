cmake_minimum_required(VERSION 3.22)
project(aoc2022-cpp CXX)

find_package(range-v3 REQUIRED)
find_package(fmt REQUIRED)

add_executable(day_01 src/day_01.cpp)
target_link_libraries(day_01 range-v3::range-v3 fmt::fmt)

add_executable(day_02 src/day_02.cpp)
target_link_libraries(day_02 range-v3::range-v3 fmt::fmt)
