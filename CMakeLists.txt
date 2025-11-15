cmake_minimum_required(VERSION 3.20)
project(DSXL C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Build subdirectories
add_subdirectory(src)
add_subdirectory(examples)
add_subdirectory(tests)

enable_testing()
