cmake_minimum_required(VERSION 3.12)
project(lab3_starter_code_syde)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab3_starter_code_syde
        lab3_binary_search_tree.cpp
        lab3_binary_search_tree.hpp
        lab3_main.cpp
        lab3_priority_queue.cpp
        lab3_priority_queue.hpp
        lab3_tests.hpp)
