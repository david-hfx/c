#include <math.h>  /* log */
#include <stdio.h> /* printf */

void print_log(double x) {
    if (x <= 0.0) {
        printf("Positive number only, please.\n");
        return;  //在没有返回值的函数中使用，结束函数
    }
    printf("log(x)=%f\n", log(x));
}

/* 位运算小技巧, 判断奇偶性 */
int is_even(int x) { return (x & 1) == 0; }

int main(void) {
    double x = 1.3;
    int y = 21;
    print_log(x);
    if (is_even(y)) {
        printf("y is a even number.\n");
    } else {
        printf("y is a odd number.\n");
    }
    return 0;
}