cmake_minimum_required(VERSION 3.25)
project(luogu)

# 100M stack
MATH(EXPR stack_size "100*1024*1024")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

add_executable(luogu main.cpp)

add_executable(p1216 dp/p1216.c)
add_executable(p1048 dp/p1048.c)
add_executable(p2871 dp/p2871.c)
add_executable(p1616 dp/p1616.c)
add_executable(p1776 dp/p1776.c)
add_executable(p1776_binary_split dp/p1776_binary_split.cpp)
add_executable(p1833 dp/p1833.cpp)
add_executable(p1855 dp/p1855.c)
add_executable(p1757 dp/p1757.cpp)
add_executable(p1064 dp/p1064.cpp)
add_executable(p2580 trie/p2580.cpp)
