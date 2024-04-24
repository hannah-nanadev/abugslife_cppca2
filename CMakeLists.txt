cmake_minimum_required(VERSION 3.25)
project(abugslife)

set(CMAKE_CXX_STANDARD 17)

add_executable(abugslife main.cpp bug.cpp board.h board.cpp)
