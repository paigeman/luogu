cmake_minimum_required(VERSION 3.25)
project(luogu)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

add_executable(luogu main.cpp)

add_executable(p1216 dp/p1216.c)
add_executable(p1048 dp/p1048.c)
add_executable(p2871 dp/p2871.c)
add_executable(p1616 dp/p1616.c)
add_executable(p1776 dp/p1776.c)
add_executable(p1776_binary_split dp/p1776_binary_split.cpp)