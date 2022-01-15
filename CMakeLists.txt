cmake_minimum_required(VERSION 3.21)
project(ObjectOrientedHW)

set(CMAKE_CXX_STANDARD 14)
set(GCC_COVERAGE_COMPILE_FLAGS "-static -static-libgcc -static-libstdc++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

include_directories(.)

add_executable(ObjectOrientedHW
        container.cpp
        container.h
        main.cpp
        plane.cpp
        plane.h
        ship.cpp
        ship.h
        train.cpp
        train.h
        vehicle.cpp
        vehicle.h)
