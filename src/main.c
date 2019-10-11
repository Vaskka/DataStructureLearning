//
//  main.c
//  test
//
//  Created by 曹志铭 on 2019/10/10.
//  Copyright © 2019 Vaskka. All rights reserved.
//

#include <stdio.h>

#include "arraylist/arraylist.h"


struct A {
    int * a;
    char* s;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    ArrayList * list = createList(0);

    
    for (int i = 0 ; i < 2048; i++) {
        struct A a;
        a.a = malloc(sizeof(int) * 3);
        a.a[0] = 2;
        a.a[1] = 3;
        a.a[2] = 4;
        a.s = "hhh";
        insert(list, 0, (void*)&a);
    }
    
    removeIndexElement(list, 20);
    
    
    for (int i = 0 ; i < getSize(list); i++) {
        printf("%d:%s\n", i, ((struct A *)get(list, i))->s);
    }
    
    
    printf("%d\n", list->size);
    printf("%d\n", list->count);

    
    return 0;
}
