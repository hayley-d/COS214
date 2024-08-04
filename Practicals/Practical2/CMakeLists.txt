cmake_minimum_required(VERSION 3.28)
project(practical_2)

set(CMAKE_CXX_STANDARD 11)

add_executable(practical_2 main.cpp
        Memento.cpp
        Memento.h
        ConcreteMemento.cpp
        ConcreteMemento.h
        Soldiers.cpp
        Soldiers.h
        CareTaker.cpp
        CareTaker.h)
