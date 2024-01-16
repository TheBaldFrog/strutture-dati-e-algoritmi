cmake_minimum_required(VERSION 3.6.0)
project(dynamic_array_data_structure)

find_package(fmt CONFIG REQUIRED)

add_executable(dynamic_array_demo main.cpp dynamic_array.cpp)
target_link_libraries(dynamic_array_demo PRIVATE fmt::fmt)
set_property(TARGET dynamic_array_demo PROPERTY CXX_STANDARD 17)