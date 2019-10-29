# 编译目标为动态库 add_library(动态库名字 SHARED 相关的.c文件)
add_library(arraylist SHARED arraylist.c ../common/struct_common.c)
