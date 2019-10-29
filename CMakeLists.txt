cmake_minimum_required(VERSION 3.10)
PROJECT(datastruct_learn)

add_subdirectory(src/linkedlist lib/linkedlist) 
add_executable(main src/main)
target_link_libraries(main linkedlist) 
