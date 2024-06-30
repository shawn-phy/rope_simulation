cmake_minimum_required(VERSION 3.1)

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED OFF)
SET(CMAKE_CXX_EXTENSIONS OFF)

project(test)

include_directories(usr/local/include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/../bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/../bin)

find_library(ROPE_LIB ropesim HINTS usr/local/lib)

add_executable(test src/test.cpp)

target_link_libraries(test PUBLIC ${ROPE_LIB})

