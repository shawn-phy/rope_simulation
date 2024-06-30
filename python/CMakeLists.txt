cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED OFF)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-O3")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Set the path to the Python executable
set(PYTHON_EXECUTABLE "/home/shawnphy/Documents/code/rope_simulation/bindings/bin/python3")

project(ropesim)

# Print the current source directory for debugging
message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")

# Adjust include directories
include_directories(${CMAKE_SOURCE_DIR}/../cpp/include)
include_directories(${CMAKE_SOURCE_DIR}/../cpp/include/ropesim_bits)
include_directories(${CMAKE_SOURCE_DIR})

# Glob source files with adjusted paths
file(GLOB SOURCE_FILES "${CMAKE_SOURCE_DIR}/../cpp/src/*.cpp")
file(GLOB HEADER_FILES "${CMAKE_SOURCE_DIR}/../cpp/include/*.hpp")
file(GLOB PYTHON_FILES "${CMAKE_SOURCE_DIR}/*.cpp" "${CMAKE_SOURCE_DIR}/*.hpp")

# Print found files for debugging
message(STATUS "SOURCE_FILES: ${SOURCE_FILES}")
message(STATUS "HEADER_FILES: ${HEADER_FILES}")
message(STATUS "PYTHON_FILES: ${PYTHON_FILES}")

# Set the path to pybind11
set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH};/home/shawnphy/Documents/code/rope_simulation/bindings/lib/python3.10/site-packages/pybind11/share/cmake")

find_package(pybind11 REQUIRED)

# Ensure that the source files are included
pybind11_add_module(ropesim
    ${SOURCE_FILES}
    ${HEADER_FILES}
    ${PYTHON_FILES}
)

target_link_libraries(ropesim PRIVATE)

# Determine the Python site-packages directory
execute_process(
    COMMAND "${PYTHON_EXECUTABLE}" -c "import site; print(site.getsitepackages()[0])"
    OUTPUT_VARIABLE PYTHON_SITE_PACKAGES
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Install the module
install(TARGETS ropesim
    COMPONENT python
    LIBRARY DESTINATION "${PYTHON_SITE_PACKAGES}"
)

# Print the installation destination for verification
message(STATUS "Python module will be installed to: ${PYTHON_SITE_PACKAGES}")