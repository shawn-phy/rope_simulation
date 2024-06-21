cmake_minimum_required(VERSION 3.22)

SET (CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED OFF)
SET(CMAKE_CXX_EXTENSIONS OFF)

PROJECT(rope_simulation CXX)


include_directories(${PROJECT_SOURCE_DIR}/src)

set(SOURCE_FILES 
    src/rope.cpp
    main.cpp)

add_executable(rope_simulation ${SOURCE_FILES})