/*
 * @Author: David
 * @Date: 2020-02-23 16:32:49
 * @Description:将十进制数转化成二进制
 */
#include <limits.h>
#include <stdio.h>

int bin(int n) {
    int ans = 0, i, k = 1, tmp = n;
    while (tmp) {
        ans += tmp % 2 * k;
        tmp /= 2;
        k *= 10;
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    printf("%d\n", bin(5));
    return 0;
}
