cmake_minimum_required(VERSION 3.8)
#требования к версии

project(fLR7)
#имя проекта

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lr7 main.cpp npc.cpp orc.cpp knight.cpp bear.cpp)
add_executable(tests tests.cpp npc.cpp orc.cpp knight.cpp bear.cpp)

enable_testing()
target_link_libraries(lr7 Threads::Threads)
target_link_libraries(tests ${GTEST_LIBRARIES} Threads::Threads)
add_test(NAME BASIC COMMAND tests)