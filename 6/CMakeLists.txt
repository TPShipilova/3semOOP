cmake_minimum_required(VERSION 3.10)

project(lab_06)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(lab_06 main.cpp npc.cpp knight.cpp bear.cpp orc.cpp)

enable_testing()
add_executable(testlr6 tests.cpp npc.cpp knight.cpp orc.cpp bear.cpp)

target_link_libraries(testlr6 ${GTEST_LIBRARIES})
add_test(NAME BASIC COMMAND testlr6)
