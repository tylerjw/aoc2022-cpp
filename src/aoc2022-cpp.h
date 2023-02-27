#pragma once


#ifdef _WIN32
  #define AOC2022_CPP_EXPORT __declspec(dllexport)
#else
  #define AOC2022_CPP_EXPORT
#endif

AOC2022_CPP_EXPORT void aoc2022_cpp();
