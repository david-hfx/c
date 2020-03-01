// #include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

typedef int SElemType;

typedef struct {
    SElemType *base; /* 栈底指针 */
    SElemType *top;  /* 栈顶指针 */
    int stacksize;   /* 当前栈的最大长度 */
} SqStack;

/* 初始化栈 */
int initStack(SqStack *s, int size) {
    s->base = (SElemType *)malloc(size * sizeof(SElemType));
    if (!s->base)
        return 0;
    s->top = s->base;
    s->stacksize = size;
    return 1;
}

int stackIsEmpty(SqStack *s) { return s->top == s->base; }

int stackIsFull(SqStack *s) { return (s->top - s->base) == s->stacksize; }

void push(SqStack *s, SElemType e) {
    if (stackIsFull(s)) {
        s->base = (SElemType *)realloc(s->base, (int)(1.1 * s->stacksize) *
                                                    sizeof(SElemType));
        s->stacksize += (int)0.1 * s->stacksize;
    }
    *s->top++ = e;
}

SElemType pop(SqStack *s) {
    if (stackIsEmpty(s)) {
        printf("stack is empty!\n");
        exit(-1);
    }
    SElemType e;
    e = *(--s->top);
    return e;
}
