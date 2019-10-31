//
//  main.c
//  test
//
//  Created by 曹志铭 on 2019/10/10.
//  Copyright © 2019 Vaskka. All rights reserved.
//


#include "linkedlist/linkedlist.h"

#include <stdio.h>


int main(int argc, const char * argv[]) {
    // insert code here...

    LinkedList * list1 = llCreateList();

    LinkedList * list2 = llCreateList();

    llAddLast(list1, (void*) 1);
    llAddLast(list1, (void*) 2);
    llAddLast(list1, (void*) 3);


    llAddLast(list2, (void*) 4);
    llAddLast(list2, (void*) 5);
    llAddLast(list2, (void*) 6);

    llAppendLinkedList(list1, list2);
    
    llIteratorInit(list1);

    while (llIteratorHasNext(list1)) {
        printf("%d\n", (int)llIteratorNext(list1));
    }

    llIteratorClose(list1);
    printf("\n\n");
    printf("%d\n", list1->size);
    printf("%d\n", list2->size);
    



    llDestory(list1);
    llDestory(list2);
    
    return 0;
}
