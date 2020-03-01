#include <stdio.h> /* printf */
#include <time.h>  /* clock */

long double recursive_factorial(int n) {
    if (n < 0) return -1;
    if (n == 0 || n == 1)
        return 1;
    else
        return n * recursive_factorial(n - 1);
}

long double cycle_factorial(int n) {
    long double ans = 1;
    int i;
    for (i = 1; i <= n; i++) ans *= i;
    return ans;
}

int main(int argc, char const* argv[]) {
    printf("请输入一个整数,q结束：");
    int n;
    const int count = 10000;
    int i;

    while (scanf("%d", &n)) {
        clock_t start1 = clock();
        for (i = 0; i < count; i++) recursive_factorial(n);
        printf("%d! = %Lf，", n, recursive_factorial(n));
        clock_t end1 = clock();
        printf("递归计算用时%fs.\n", (double)(end1 - start1) / CLOCKS_PER_SEC);

        clock_t start2 = clock();
        for (i = 0; i < count; i++) cycle_factorial(n);
        printf("%d! = %Lf，", n, cycle_factorial(n));
        clock_t end2 = clock();
        printf("循环计算用时%fs.\n", (double)(end2 - start2) / CLOCKS_PER_SEC);
        printf("请输入一个整数,q结束：");
    }

    return 0;
}
