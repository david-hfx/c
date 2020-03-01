#ifndef _SQ_STACK_H
#define _SQ_STACK_H

typedef int SElemType;

typedef struct {
    SElemType *base; /* 栈底指针 */
    SElemType *top;  /* 栈顶指针 */
    int stacksize;   /* 当前栈的最大长度 */
} SqStack;

int initStack(SqStack *s, int size);
int stackIsEmpty(SqStack *s);
int stackIsFull(SqStack *s);
void push(SqStack *s, SElemType e);
SElemType pop(SqStack *s);

#endif
