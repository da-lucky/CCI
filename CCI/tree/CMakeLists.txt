cmake_minimum_required(VERSION 3.7.1)
project(tree)

set(CMAKE_CXX_STANDARD 14)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})

include_directories(../common/)

add_executable(tree main.cpp ../common/node.h ../common/utils.h tree.hpp)
