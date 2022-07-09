cmake_minimum_required(VERSION 3.15)
project(sf5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(sf5
        main.cpp
        vendingmachine.cpp
        vendingmachine.h snack.cpp snack.h snackslot.cpp snackslot.h)
