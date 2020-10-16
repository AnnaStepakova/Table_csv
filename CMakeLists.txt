cmake_minimum_required(VERSION 3.5)

project(Table_csv)

add_executable(main main.cpp table.cpp)

add_executable(runTests table.cpp tests/test.cpp)
target_link_libraries(runTests gtest pthread)


