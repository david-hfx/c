#include <stdio.h> /* printf */

void print_array(int a[], int len) {
    int i;
    putchar('{');
    for (i = 0; i < len; i++) {
        printf("%d, ", a[i]);
    }
    putchar('}');
    putchar('\n');
}
int main(int argc, char const *argv[]) {
    // 数组的各种赋值方法
    int a[] = {1, 2, 3, 4, 5, 7};
    int b[5] = {1, 2, 3, 4, 5};
    int c[4] = {1, 2};
    int d[4] = {[3] = 1};  // C99特性
    print_array(a, 6);
    print_array(b, 5);
    print_array(c, 4);
    print_array(d, 4);

    int e[5];
    for (int i = 0; i < 5; i++) e[i] = b[i];
    print_array(e, 5);

    return 0;
}
