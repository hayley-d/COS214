cmake_minimum_required(VERSION 3.28)
project(Practical3)

set(CMAKE_CXX_STANDARD 17)

add_executable(Practical3 main.cpp
        UnitComponent.h
        Infantry.h
        Infantry.cpp
        Cavalry.cpp
        Cavalry.h
        Artillery.cpp
        Artillery.h
        CompositeUnit.h
        Legion.cpp
        Legion.h
        Direction.h
        Cohort.cpp
        Cohort.h
        Century.cpp
        Century.h
)
