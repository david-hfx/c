#include "stack.h"

static sp stack[512];
static int top = 0;

void push(sp p) { stack[top++] = p; }

sp pop(void) { return stack[--top]; }

int is_empty(void) { return top == 0; }
