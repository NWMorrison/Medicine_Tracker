cmake_minimum_required(VERSION 3.26)
project(Medicine_Tracker)

set(CMAKE_CXX_STANDARD 23)

add_executable(Medicine_Tracker main.cpp
        Medicine_Header.h
        Medicine_Implementation.cpp)
