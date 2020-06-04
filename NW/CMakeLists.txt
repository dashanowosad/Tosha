cmake_minimum_required(VERSION 3.15)
project(NW)

set(CMAKE_CXX_STANDARD 17)

add_executable(NW main.cpp NW.cpp NW.h Model.cpp Model.h)