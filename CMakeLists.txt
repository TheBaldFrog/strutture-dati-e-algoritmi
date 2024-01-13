cmake_minimum_required(VERSION 3.6.0)
project(dsa VERSION 0.1.0 LANGUAGES C CXX)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE
    ./insertion_sort.cpp
)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)