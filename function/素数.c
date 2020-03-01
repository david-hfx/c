#include <math.h>  /* sqrt */
#include <stdio.h> /* printf */

/*
 *判断输入的数是否为素数
 */
int is_prime(int n) {
    if (n <= 1 || (n > 2 && n % 2 == 0) || (n > 3 && n % 3 == 0)) return 0;
    int i;
    int ceil = (int)sqrt((double)n);
    for (i = 2; i <= ceil; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main(int argc, char const *argv[]) {
    int i;
    for (i = 1; i <= 100; i++) {
        if (is_prime(i)) printf("%d\n", i);
    }
    return 0;
}
