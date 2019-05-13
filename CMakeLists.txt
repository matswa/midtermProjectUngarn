cmake_minimum_required(VERSION 3.8)
project(OOPproject)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp car.cpp car.h bus.cpp bus.h rental.cpp rental.h functions.cpp functions.h)
add_executable(OOPproject ${SOURCE_FILES})