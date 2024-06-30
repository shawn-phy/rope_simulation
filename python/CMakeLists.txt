cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED OFF)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-O3")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")


#the following lines should be deleted on production
set(PYTHON_LIBRARY_DIR "bindings/lib/python3.10/site-packages")
set(PYTHON_EXECUTABLE "/usr/bin/python3")
# remember to remove above lines


set(pybind11_DIR "/home/shawnphy/Documents/code/rope_simulation/bindings/lib/python3.10/site-packages/pybind11/share/cmake/pybind11")

project(ropesim)

include_directories(${CMAKE_SOURCE_DIR}/cpp/include/ropesim_bits)
include_directories(${CMAKE_SOURCE_DIR}/python)

file(GLOB SOURCE_FILES "${CMAKE_SOURCE_DIR}/cpp/src/*.cpp")
file(GLOB HEADER_FILES "${CMAKE_SOURCE_DIR}/cpp/include/*.hpp")
file(GLOB PYTHON_FILES "${CMAKE_SOURCE_DIR}/python/*.cpp" "${CMAKE_SOURCE_DIR}/python/*.hpp")


source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES} ${HEADER_FILES} ${PYTHON_FILES} )

find_package(pybind11 REQUIRED)

pybind11_add_module(ropesim
${SOURCE_FILES}
${HEADER_FILES}
${PYTHON_FILES}
)

target_link_libraries(ropesim PUBLIC)

install(TARGETS ropesim
COMPONENT python
LIBRARY DESTINATION "${PYTHON_LIBRARY_DIR}"
)




