//
//  arraylist.h
//  arraylist
//
//  Created by 曹志铭 on 2019/10/10.
//  Copyright © 2019 Vaskka. All rights reserved.
//

#ifndef arraylist_h
#define arraylist_h

#include <stdio.h>
#include <stdlib.h>
#include "../common/struct_common.h"

#define MAX_SIZE 65536
#define EACH_APPEND_SIZE 1024


typedef struct ArrayList {
    
    void** innerArray;
    
    // 真实个数
    int size;
    
    // 已分配个数
    int count;
    
    
} ArrayList;

// 创建一个list
ArrayList* createList(int initSize);

// 增加一个element
void add(ArrayList* list, void* ele);

// 插入一个element
void insert(ArrayList* list, int index, void* ele);

// 删除index位置的element（不会回收remove的地址所分配的内存，使用时需要注意内存泄漏问题）
void removeIndexElement(ArrayList* list, int index);

// 删除搜索到的第一个element（不会回收remove的地址所分配的内存，使用时需要注意内存泄漏问题）
void removeElement(ArrayList* list, void* ele);

// 获取第index的ele
void* get(const ArrayList* list, int index);

// 获取真实大小
int getSize(const ArrayList* list);

// 内部检查扩展空间
void _extendSize(ArrayList* list);

#endif /* arraylist_h */
