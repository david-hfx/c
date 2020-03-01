//
// Created by david on 2020/2/27.
//

#include "./stack/SqStack.h"
#include <stdio.h>

int main(int argc, char const *argv[]) {
    SqStack s;
    initStack(&s, 10);
    for (int i = 0; i < 10; i++)
        push(&s, i);

    printf("%d\n", stackIsFull(&s));

    SElemType e;
    while (!stackIsEmpty(&s)) {
        e = pop(&s);
        printf("%d\n", e);
    }
    return 0;
}
