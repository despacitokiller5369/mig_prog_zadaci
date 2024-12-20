cmake_minimum_required(VERSION 3.10)

project(math_algorithms)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

set(SOURCES
    src/main.cpp
    src/sieve.cpp
)

add_executable(math_algorithms ${SOURCES})
