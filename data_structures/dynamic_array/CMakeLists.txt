cmake_minimum_required(VERSION 3.6.0)
project(dynamic_array_data_structure_non_template)

add_executable(dynamic_array_non_template_demo dynamic_array_demo.cpp dynamic_array.cpp)
set_property(TARGET dynamic_array_non_template_demo PROPERTY CXX_STANDARD 20)

add_subdirectory(unit_tests)

#message("${PROJECT_NAME}_demo")