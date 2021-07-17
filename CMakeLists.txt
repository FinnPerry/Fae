project(fae)
cmake_minimum_required(VERSION 3.16.3)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(external)
add_subdirectory(core)
add_subdirectory(demo)
add_subdirectory(tests)
