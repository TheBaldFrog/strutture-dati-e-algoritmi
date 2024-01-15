cmake_minimum_required(VERSION 3.6.0)
project(dynamic_array_data_structure)

add_executable(dynamic_array_demo main.cpp dynamic_array.cpp)
set_property(TARGET dynamic_array_demo PROPERTY CXX_STANDARD 17)