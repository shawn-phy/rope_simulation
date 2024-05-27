cmake_minimum_required(VERSION 3.22)

SET (CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_EXTENSIONS OFF)

PROJECT(rope_simulation CXX)

include_directories(src)

add_executable(rope_simulation main.cpp)

