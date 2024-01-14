cmake_minimum_required(VERSION 3.6.0)
project(dsa)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED On)

add_executable(insertion_sort insertion_sort.cpp)
add_executable(selection_sort selection_sort.cpp)
add_executable(bubble_sort bubble_sort.cpp)
add_executable(merge_sort merge_sort.cpp)
add_executable(quick_sort quick_sort.cpp)
add_executable(binary_search binary_search.cpp)