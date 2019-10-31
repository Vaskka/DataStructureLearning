# 接口文档

## ArrayList

> 类范型的、可自动增长的list结构。
> 
> 实现：src/arraylist

### 结构属性

```cpp
#define DEFAULT_INIT_SIZE 64
#define MAX_SIZE 65536
#define EACH_APPEND_SIZE 1024

typedef struct ArrayList {
    
    void** innerArray;
    
    // 真实个数
    int size;
    
    // 已分配个数
    int count;
    
    
} ArrayList;
```

### 初始化

```c
// 创建一个list
ArrayList* alCreateList(int initSize);
```

#### 描述

返回已经经过初始化的ArrayList\*。

#### 参数
 
+ initSize：可指定初始化时分配多少个sizeof(void\*)，传入非正整数时初始化为 DEFAULT_INIT_SIZE。

### 在其后增加一个元素

```c
// 增加一个element
void alAdd(ArrayList* list, void* ele);
```

#### 描述

当空间不足时会自动扩容，最大不超过 MAX_SIZE * sizeof(void\*)。

#### 参数
 
+ list: list引用。
+ ele: 要添加的元素。

### 在某位置增加一个元素

```c
// 插入一个element
void alInsert(ArrayList* list, int index, void* ele);
```

#### 描述

当空间不足时会自动扩容，最大不超过 MAX_SIZE * sizeof(void\*)。

#### 参数
 
+ list: list引用。
+ index: 新元素的index。
+ ele: 要添加的元素。

### 在某位置删除一个元素

> 注意，如果调用此接口后删除的元素无法访问到，则会造成内存泄漏问题，实现上无法判断void\*是否已经分配了内存。

```c
// 删除index位置的element（不会回收remove的地址所分配的内存，使用时需要注意内存泄漏问题）
void alRemoveIndexElement(ArrayList* list, int index);
```

#### 描述

删除指定位置上的元素。

#### 参数
 
+ list: list引用。
+ index: 要删除元素的index。

### 删除找到的第一个指定元素

> 注意，如果调用此接口后删除的元素无法访问到，则会造成内存泄漏问题，实现上无法判断void\*是否已经分配了内存。

```c
// 删除搜索到的第一个element（不会回收remove的地址所分配的内存，使用时需要注意内存泄漏问题）
void alRemoveElement(ArrayList* list, void* ele);
```

#### 描述

删除指定的元素。

#### 参数
 
+ list: list引用。
+ ele: 要删除的元素。

### 获取指定index的元素

```c
// 获取第index的ele
void* alGet(const ArrayList* list, int index);
```

#### 描述

获取指定index的元素。

#### 参数
 
+ list: list引用。
+ index: 要获取的元素的index。


### 获取当前有多少个元素

```c
// 获取真实大小
int alGetSize(const ArrayList* list);
```

#### 描述

返回元素个数

#### 参数
 
+ list: list引用。








