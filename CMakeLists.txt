cmake_minimum_required(VERSION 3.25)
project(luogu)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

add_executable(luogu main.cpp)

add_executable(p1216 dp/p1216.c)
add_executable(p1048 dp/p1048.c)