//
//  linkedlist.h
//  linkedlist
//
//  Created by Vaskka on 2019/10/28.
//  Copyright © 2019 Vaskka. All rights reserved.
//

#ifndef linkedlist_h
#define linkedlist_h

#include "../common/struct_common.h"

// 内部节点
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

// 创建一个list
LinkedList* createList();

// 增加一个element在尾部
void addLast(LinkedList* list, void* ele);

// 增加一个element在首部
void addFirst(LinkedList* list, void* ele);

// 获取头部第一个元素的引用，相当于队列的peek
void* getFirst(const LinkedList* list);

// 获取尾部第一个元素的引用，相当于栈的peek
void* getLast(const LinkedList* list);

// 插入一个element
void insert(LinkedList* list, int index, void* ele);

// 删除首部第一个element（不会回收内部用户数据所分配的内存，只会回收节点的内存，使用时需要注意内存泄漏问题）
void removeFirstElement(LinkedList* list);

// 删除尾部第一个element（不会回收内部用户数据所分配的内存，只会回收节点的内存，使用时需要注意内存泄漏问题）
void removeLastElement(LinkedList* list);

// 获取第index的ele, index < 0 等效于 index == 0, index >= size 等效于 index == size
void* get(const LinkedList* list, int index);

// 获取真实大小
int getSize(const LinkedList* list);

// 销毁一个list, 不会回收内部用户数据所分配的内存，只会回收节点的内存，使用时需要注意内存泄漏问题）
void destory(LinkedList* list);

// 销毁list并释放内部用户数据
void destoryAndFree(LinkedList* list);

#endif /* linkedlist_h */
