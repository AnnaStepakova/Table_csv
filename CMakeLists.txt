cmake_minimum_required(VERSION 3.5)

project(Table_csv)
include(gtest.cmake)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(main main.cpp table.cpp)

# GTest needs threading support
find_package (Threads)
add_executable(runTests table.cpp tests/test.cpp)
target_link_libraries(runTests gtest  ${CMAKE_THREAD_LIBS_INIT})
