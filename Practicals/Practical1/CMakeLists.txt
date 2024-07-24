cmake_minimum_required(VERSION 3.28)
project(Practical1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Practical1 main.cpp
        Menu.cpp
        Menu.h
        MenuItem.cpp
        MenuItem.h
        Course.cpp
        Course.h
        Dessert.cpp
        Dessert.h
        MainCourse.cpp
        MainCourse.h
        Starter.cpp
        Starter.h)
