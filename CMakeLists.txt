cmake_minimum_required(VERSION 3.6.0)

set(VCPKG_TARGET_TRIPLET x64-windows)
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING "Vcpkg toolchain file")

project(data_structures_and_algorithms VERSION 0.1.0)

# add_subdirectory(sorting_algorithms)
# message(PROJECT_SOURCE_DIR="${PROJECT_SOURCE_DIR}")
# add_subdirectory(data_structures/dynamic_array)
add_subdirectory(data_structures/dynamic_array/unit_tests)