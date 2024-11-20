cmake_minimum_required(VERSION 3.10)

project(string_processing)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_C_FLAGS "/utf-8")
set(CMAKE_CXX_FLAGS "/utf-8")

include_directories(include)

set(SOURCES
    src/main.cpp
    src/string_kiloo.cpp
    src/trie_kiloo.cpp
    src/patricia_kiloo.cpp
)

add_executable(string_processing ${SOURCES})
