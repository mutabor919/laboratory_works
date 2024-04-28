cmake_minimum_required(VERSION 3.26)
project(13_laba C)

set(CMAKE_C_STANDARD 11)

add_executable(13_laba main.c
        libs/algorithms/array/array.c
        libs/algorithms/array/array.h
        libs/algorithms/algorithm.c
        libs/algorithms/algorithm.h
        libs/data_structures/unordered_array_set/unordered_array_set.c
        libs/data_structures/unordered_array_set/unordered_array_set.h
        libs/str/string/string_.c
        libs/str/string/string_.h
)

add_subdirectory(libs)
target_link_libraries(13_laba str)
target_link_libraries(13_laba data_structures)
target_link_libraries(13_laba algorithms)

