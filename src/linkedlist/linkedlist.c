#include "linkedlist.h"


// 创建一个list
LinkedList* createList() {
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    list->size = 0;
    list->head = list->tail = NULL;

    return list;
}

// 增加一个element在尾部
void addLast(LinkedList* list, void* ele) {

    LinkedListItem* item = (LinkedListItem*) malloc(sizeof(LinkedListItem));
    item->value = ele;
    item->prePointer = NULL;
    item->nextPointer = NULL;

    // 链表为空
    if (list->size == 0) {
        list->head = item;
        list->tail = item;
        list->size++;
    }
    else {
        //链表不为空
        list->tail->nextPointer = item;
        item->prePointer = list->tail;
        list->tail = item;

        list->size++;
    }

}

// 增加一个element在首部
void addFirst(LinkedList* list, void* ele) {
    LinkedListItem* item = (LinkedListItem*) malloc(sizeof(LinkedListItem));
    item->value = ele;
    item->prePointer = NULL;
    item->nextPointer = NULL;

    // 链表为空
    if (list->size == 0) {
        list->head = item;
        list->tail = item;
        list->size++;
    }
    else {
        // 链表不为空
        list->head->prePointer = item;
        item->nextPointer = list->head;
        list->head = item;
        list->size++;

        
    }

}

// 获取头部第一个元素的引用，相当于队列的peek
void* getFirst(const LinkedList* list) {
    return list->head->value;
}

// 获取尾部第一个元素的引用，相当于栈的peek
void* getLast(const LinkedList* list) {
    return list->tail->value;
}

// 插入一个element, index < 0 等效于 index == 0, index >= size 等效于 index == size
void insert(LinkedList* list, int index, void* ele) {

    if (index <= 0) {
        addFirst(list, ele);
        return;
    }

    if (index >= list->size) {
        addLast(list, ele);
        return;
    }

    // find index node
    int i = 0;
    LinkedListItem* curr = list->head;
    while (i < index) {
        curr = curr->nextPointer;
        i++;
    }

    // init node
    LinkedListItem* newItem = (LinkedListItem*) malloc(sizeof(LinkedListItem));
    newItem->value = ele;
    newItem->prePointer = NULL;
    newItem->nextPointer = NULL;

    // do insert

    if (list->size == 0) {
        list->head = list->tail = newItem;
    }
    else {
        newItem->prePointer = curr->prePointer;
        newItem->nextPointer = curr;
        curr->prePointer->nextPointer = newItem;
        curr->prePointer = newItem;
    }
    list->size++;
}

// 删除首部第一个element（不会回收内部用户数据所分配的内存，只会回收节点的内存，使用时需要注意内存泄漏问题）
void removeFirstElement(LinkedList* list) {
    if (list->size == 0) {
        return;
    }

    LinkedListItem* orginalHead = list->head->nextPointer;
    list->head = list->head->nextPointer;
    free(orginalHead);

    list->size--;
    if (list->size == 0) {
        list->head = list->tail = NULL;
    }
}

// 删除尾部第一个element（不会回收内部用户数据所分配的内存，只会回收节点的内存，使用时需要注意内存泄漏问题）
void removeLastElement(LinkedList* list) {
    if (list->size == 0) {
        return;
    }

    LinkedListItem* newTail = list->tail->prePointer;
    free(list->tail);
    list->tail = newTail;

    list->size--;
    if (list->size == 0) {
        list->head = list->tail = NULL;
    }
}

// 获取第index的ele, index < 0 等效于 index == 0, index >= size 等效于 index == size
void* get(const LinkedList* list, int index) {
    if (index < 0) {
        index = 0;
    }

    if (index >= list->size) {
        index = list->size - 1;
    }

    // find which is index
    int i = 0;
    LinkedListItem* curr = list->head;
    while (i < index) {
        curr = curr->nextPointer;
        i++;
    }

    return curr->value;
}

// 获取真实大小
int getSize(const LinkedList* list) {
    return list->size;
}

// 销毁一个list（不会回收内部用户数据所分配的内存，只会回收节点的内存，使用时需要注意内存泄漏问题）
void destory(LinkedList* list) {
    while (list->size != 0) {
        removeLastElement(list);
    }

    free(list);
}

// 销毁list并释放内部用户数据
void destoryAndFree(LinkedList* list) {
    while (list->size != 0) {
        void* val = getLast(list);
        free(val);
        removeLastElement(list);
    }

    free(list);
}
