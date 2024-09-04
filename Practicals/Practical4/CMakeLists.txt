cmake_minimum_required(VERSION 3.28)
project(Practical4)

set(CMAKE_CXX_STANDARD 17)

add_executable(Practical4 main.cpp
        Iterator.h
        FarmIterator.h
        FarmIterator.cpp
        FarmUnit.h
        TraversalStrategy.h
        BFSStrategy.h
        BFSStrategy.cpp
        DFSStrategy.cpp
        DFSStrategy.h
        FarmUnit.cpp
        FarmComposite.h
        CropField.cpp
        CropField.h
        Farm.cpp
        Farm.h
        Crop.h
        SoilState.h
        DrySoil.cpp
        DrySoil.h
        FruitfulSoil.cpp
        FruitfulSoil.h
        FloodedSoil.cpp
        FloodedSoil.h
        Barn.cpp
        Barn.h
        Truck.h
        FertilizerTruck.cpp
        FertilizerTruck.h
        LogisticsTruck.cpp
        LogisticsTruck.h
        Event.h
)
