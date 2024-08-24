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
        Legion.cpp
        Legion.h
        Direction.h
        TacticalCommand.cpp
        TacticalCommand.h
        BattleStrategy.h
        Flanking.cpp
        Flanking.h
        Ambush.cpp
        Ambush.h
        Fortification.cpp
        Fortification.h
        LegionFactory.h
        OpenField.cpp
        OpenField.h
        OpenFieldFactory.h
        Riverbank.cpp
        Riverbank.h
        RiverbankFactory.h
        TacticalMemento.h
        TacticalPlanner.cpp
        TacticalPlanner.h
        WarArchives.cpp
        WarArchives.h
        Woodlands.cpp
        Woodlands.h
)
