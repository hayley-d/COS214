cmake_minimum_required(VERSION 3.28)
project(tutorial1)

set(CMAKE_CXX_STANDARD 17)

add_executable(tutorial1 main.cpp
        A.cpp
        A.h
        B.cpp
        B.h
        C.cpp
        C.h
        D.cpp
        D.h
        Calculator.cpp
        Calculator.h)
