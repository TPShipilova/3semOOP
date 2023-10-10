cmake_minimum_required(VERSION 3.10)
project(oop)
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(oop main.cpp binary.cpp)

enable_testing()
add_executable(test_01 test.cpp binary.cpp)
target_link_libraries(test_01 ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND test_01)