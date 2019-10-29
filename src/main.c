//
//  main.c
//  test
//
//  Created by 曹志铭 on 2019/10/10.
//  Copyright © 2019 Vaskka. All rights reserved.
//


#include "linkedlist/linkedlist.h"

#include <stdio.h>
struct A {
    int a;
    char* s;
};

int main(int argc, const char * argv[]) {
    // insert code here...

    LinkedList * list = createList();


    for (int i = 0 ; i < 3; i++) {
        int a = i;
        /*
        a.a = i;

        a.s = "hhh";
        */
        addFirst(list, (void*)&a);
    }
    
    // while (getSize(list)) {
    //    int curr = *((int*) getLast(list));
    //     printf("%d\n", curr);
    //     removeLastElement(list);
    // }

    printf("%d\n\n", *(int*)(list->head->value));
        printf("%d\n\n", *(int*)(list->head->nextPointer->value));
            printf("%d\n\n", *(int*)(list->head->nextPointer->nextPointer->value));
    
    printf("%d\n", list->size);
    destory(list);
    
    return 0;
}
