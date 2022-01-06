cmake_minimum_required(VERSION 3.20)
project(8queens C)

set(CMAKE_C_STANDARD 99)

add_subdirectory(queens)
add_executable(8queens main.c)
target_link_libraries(8queens PUBLIC queens)