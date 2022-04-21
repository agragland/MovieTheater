cmake_minimum_required(VERSION 3.21)
project(MovieTheater)

set(CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(MovieTheater main.cpp MovieTheater.cpp MovieTheater.h TheaterTest.cpp TheaterTest.h)
