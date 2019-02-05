cmake_minimum_required(VERSION 2.8)

project(ExampleProject)

# Old way to set C++ standard (compiler dependent)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
# New CMake (3.1+) way to set C++ standard (compiler independent)
# set(CMAKE_CXX_STANDARD 11)

# Get the Boost package
find_package(Boost 1.45.0 REQUIRED COMPONENTS program_options)

# Example of some diagnostic messages that might help you debug build issues
message("Boost_FOUND: ${Boost_FOUND}")
message("Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
message("Boost_LIBRARIES: ${Boost_LIBRARIES}")

# This includes the Boost header files that our program needs access to
include_directories(${Boost_INCLUDE_DIRS})

# Specify our executable
add_executable(example-executable Example.cpp)

# Here we link our compiled executable to the Boost library
# Try commenting it out and see what happens
target_link_libraries(example-executable ${Boost_LIBRARIES})