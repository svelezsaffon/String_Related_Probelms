cmake_minimum_required(VERSION 3.1)
project(strings)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(strings ${SOURCE_FILES} string_problems.h)