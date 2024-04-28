cmake_minimum_required(VERSION 3.25)
project(abugslife)

set(CMAKE_CXX_STANDARD 17)

add_executable(abugslife main.cpp bug.cpp board.h board.cpp Crawler.cpp Crawler.h
        Hopper.cpp
        Hopper.h
        Meanderer.cpp
        Meanderer.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML-2.5.1/include)
target_link_libraries(abugslife sfml-system sfml-window sfml-graphics sfml-audio)