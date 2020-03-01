/*
 * @Author: David
 * @Date: 2020-02-24 20:52:27
 * @Github: https://github.com/david-hfx
 * @Description: 使用栈实现逆序打印数组,栈满足后进先出原则，last in first out
 * LIFO
 */
#include <stdio.h> /* printf */
#define STACKSPACE 512
char stack[STACKSPACE];
int top = 0;

void push(char c) { stack[top++] = c; }

char pop(void) { return stack[--top]; }

int is_empty(void) { return top == 0; }

// int is_full(void) { return top >= STACKSPACE; }

int main(int argc, char const *argv[]) {
    push('a');
    push('b');
    push('c');

    while (!is_empty()) {
        printf("%c\n", pop());
    }
    return 0;
}
