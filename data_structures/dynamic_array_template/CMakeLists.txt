cmake_minimum_required(VERSION 3.6.0)
project(dynamic_array_data_structure_template)

add_library(dynamic_arr INTERFACE)
target_include_directories(dynamic_arr INTERFACE .)

add_executable(dynamic_array_template_demo dynamic_array_demo.cpp)
target_link_libraries(dynamic_array_template_demo PRIVATE dynamic_arr)

set_property(TARGET dynamic_array_template_demo PROPERTY CXX_STANDARD 20)

add_subdirectory(unit_tests)