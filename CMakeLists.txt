cmake_minimum_required(VERSION 3.10)
PROJECT(datastruct_learn)

# add_subdirectory(其模块的CMakeLists.txt的路径 目标路径)
add_subdirectory(src/linkedlist lib/linkedlist) 
add_subdirectory(src/arraylist lib/arraylist)

# add_executable(可执行文件的名字 main函数源文件路径))
add_executable(main src/main)

# target_link_libraries(可执行文件名字 需要链接的动态库))
target_link_libraries(main linkedlist) 
