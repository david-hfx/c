#include <stdio.h> /* printf scanf */

int main(void) {
    printf(
        "请输入两个整数a,b，"
        "输入格式为\"a b\":\n");
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d + %d = %d\n", a, b, a + b);
    return 0;
}