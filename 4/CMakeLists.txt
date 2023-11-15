cmake_minimum_required(VERSION 3.8)

project(main)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDART 17) #стандарт языка с++
set(CMAKE_CXX_STANDART_REQUIRED ON) #без соответствия стандарту не будет собран

add_executable(main main.cpp point.cpp rectangle.cpp trapezia.cpp romb.cpp vector.cpp)