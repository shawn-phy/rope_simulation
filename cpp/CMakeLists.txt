cmake_minimum_required(VERSION 3.22)

SET (CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED OFF)
SET(CMAKE_CXX_EXTENSIONS OFF)

PROJECT(rope_simulation CXX)


include_directories(usr/local/include)

aux_source_directory(src SRC_FILES)

set(PROJECT_SOURCE_DIR "src")
set(PROJECT_INCLUDE_DIR "include/ropesim_bits")


set(SOURCE_FILES 
${PROJECT_SOURCE_DIR}/rope.cpp
${PROJECT_INCLUDE_DIR}/rope.hpp)


source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})


add_library(ropesim SHARED ${SOURCE_FILES})

target_include_directories(ropesim PRIVATE include/ropesim_bits)

install(TARGETS ropesim DESTINATION lib)

install(FILES include/ropesim DESTINATION include)

install(DIRECTORY include/ropesim_bits DESTINATION include)



#add_executable(rope_simulation ${SOURCE_FILES})