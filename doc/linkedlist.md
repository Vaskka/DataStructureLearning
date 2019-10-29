# 接口文档

## LinkedList

> 一种类范型的双链表结构。
> 
> 实现：src/arraylist

### 结构属性

```cpp
// inner node
typedef struct LinkedListItem {

    void* value;

    struct LinkedListItem* prePointer;

    struct LinkedListItem* nextPointer;

} LinkedListItem;


// linkedlist
typedef struct LinkedList {
    
    LinkedListItem* head;

    LinkedListItem* tail;

    int size;
    
} LinkedList;
```

### 初始化

```cpp
// 创建一个list
LinkedList* createList(void);
```

#### 描述

返回已经经过初始化的LinkedList\*。

#### 参数
 
None

### 尾部增加新元素

```cpp
// 创建一个list
void addLast(LinkedList* list, void* ele);s
```

#### 描述

增加一个element在尾部

#### 参数
 
+ list: LinkedList\*, 链表引用
+ ele: void\*, 增加元素的引用

### 头部增加新元素

```cpp
void addFirst(LinkedList* list, void* ele);
```

#### 描述

增加一个element在头部

#### 参数
 
+ list: LinkedList\*, 链表引用
+ ele: void\*, 增加元素的引用

### 获取头部元素引用

```cpp
void* getFirst(const LinkedList* list);
```

#### 描述

获取头部第一个元素的引用


#### 参数

+ list: const LinkedList\* 链表引用

### 获取尾部引用

```cpp
void* getLast(const LinkedList* list);
```

#### 描述

获取尾部第一个元素的引用

#### 参数

+ list: const LinkedList\* 链表引用

### 插入一个元素

```cpp
void insert(LinkedList* list, int index, void* ele);
```

#### 描述

在指定位置插入元素，index < 0 等效于 index == 0, index >= size 等效于 index == size

#### 参数

+ list: LinkedList\* 链表引用
+ index: int 插入元素的指定位置
+ ele: void\* 插入元素的引用

### 删除首部元素

```cpp
void removeFirstElement(LinkedList* list);
```

#### 描述

删除首部第一个element（不会回收内部用户数据所分配的内存，只会回收节点的内存，使用时需要注意内存泄漏问题）

####  参数

+ list: const LinkedList\* 链表引用

### 删除尾部元素

```cpp
void removeLastElement(LinkedList* list);
```

#### 描述

删除尾部第一个element（不会回收内部用户数据所分配的内存，只会回收节点的内存，使用时需要注意内存泄漏问题）

### 获取第index个元素

```cpp
void* get(const LinkedList* list, int index);
```

#### 描述

获取第index的ele, index < 0 等效于 index == 0, index >= size 等效于 index == size

#### 参数

+ list: const LinkedList\* 链表引用
+ index: int 元素位置

### 获取链表长度

```cpp
void* get(const LinkedList* list, int index);
```

#### 描述

获取链表长度

#### 参数

+ list: const LinkedList\* 链表引用

### 销毁一个链表

```cpp
void destory(LinkedList* list);
```

#### 描述

销毁一个list, 不会回收内部用户数据所分配的内存，只会回收节点的内存，使用时需要注意内存泄漏问题）

#### 参数

+ list: const LinkedList\* 链表引用

### 销毁链表并自动释放用户数据

```cpp
void destoryAndFree(LinkedList* list);
```

#### 描述

销毁list并释放内部用户数据

#### 参数

+ list: const LinkedList\* 链表引用
