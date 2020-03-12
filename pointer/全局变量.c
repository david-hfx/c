#include <stdio.h>

/**
 * 全局变量只能用常量表达式初始化
 * i和c的地址在编译链接时确定了，不需要运行时确定，因此这种方式是合理的
 */
int i;
int *pi = &i;
char c;
char *pc = &c;

int main(int argc, char const *argv[]) {
    printf("pi=%p, pc=%p\n", pi, pc);
    return 0;
}
