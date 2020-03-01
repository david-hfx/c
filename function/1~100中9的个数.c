#include <stdio.h> /* printf */

/*
 *求解数字n中有多少个9
 */
unsigned int countn(unsigned int n) {
    unsigned int count = 0;
    unsigned int number;
    do {
        number = n % 10;
        n /= 10;
        if (number == 9) ++count;
    } while (n != 0);
    return count;
}

/*
 *求解1~n中有多少个数字9
 */
unsigned int count9(unsigned int n) {
    unsigned int count = 0;
    unsigned int i;
    for (i = 1; i <= n; i++) {
        count += countn(i);
    }
    return count;
}

int main(int argc, char const* argv[]) {
    printf("请输入一个正整数：");
    unsigned int n;
    scanf("%u", &n);
    printf("1~%u中共有%u个数字9.\n", n, count9(n));
    return 0;
}
