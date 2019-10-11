# DataStructureLearning
数据结构回炉重学，使用纯c实现一遍常用数据结构，复习考研用。

# 已完成的数据结构

> 详细接口文档参见doc/%struct_name%.md
> 

src/common/struct_common.h 中定义的是常用的一些工具，例如错误处理等。


## ArrayList

使用 void\* 类型实现类范型的、自动增长的list结构。使用时removeIndexElement(ArrayList* list, int index)和removeElement(ArrayList* list, void* ele)如果传递的是已经分配内存的指针，则需要注意内存泄漏的问题。实现上无法检查存储的void\*类型的数据是否分配过内存，因此不做free处理。

