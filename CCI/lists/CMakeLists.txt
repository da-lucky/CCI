cmake_minimum_required(VERSION 3.7.1)
project(lists)

set(CMAKE_CXX_STANDARD 14)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})

include_directories(../common/)

add_executable(lists main.cpp)