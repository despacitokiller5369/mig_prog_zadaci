cmake_minimum_required(VERSION 3.10)

project(graph_algorithms)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

set(SOURCES
    src/main.cpp
    src/graph.cpp

    include/graph.h
)

add_executable(graph_algorithms ${SOURCES})
