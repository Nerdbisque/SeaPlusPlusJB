cmake_minimum_required(VERSION 3.26)
project(SeaPlusPlus)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(SeaPlusPlus
        Main.cpp
        Main.h)
