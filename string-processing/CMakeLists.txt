cmake_minimum_required(VERSION 3.10)

project(string_processing)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

set(SOURCES
    src/main.cpp
    src/string_kiloo.cpp

    include/string_kiloo.h
)

add_executable(string_processing ${SOURCES})
