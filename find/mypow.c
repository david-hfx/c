/*
 * @Author: David
 * @Date: 2020-02-22 23:54:18
 * @Description:pow(x,n)的递归算法，复杂度为log(n)
 */
#include <limits.h>
#include <stdio.h>

double fastpow(double x, long long n) {
    /* base case */
    if (n == 0) {
        return 1.0;
    }
    double half = fastpow(x, n >> 1);
    if ((n & 1) == 0) {
        return half * half;
    } else {
        return half * half * x;
    }
}
/**
 * @description:pow函数的递归算法
 * @param double x 底数
 * @param int n 指数
 * @return: double x^n
 */
double recursive_mypow(double x, int n) {
    /* 可能出现n=INT_MIN -n=INT_MAX导致越界 */
    long long N = n;

    if (x == 0 || x == 1) return x;
    if (x == -1) return (N & 1) == 1 ? -1 : 1;

    if (N < 0) {
        x = 1 / x;
        N = -N;
    }
    return fastpow(x, N);
}

/**
 * @description:快速幂算法 循环版
 * @param double x 底数
 * @param int n 指数
 * @return: x^n
 */
double cycle_mypow(double x, int n) {
    /* 可能出现n=INT_MIN -n=INT_MAX导致越界 */
    long long N = n;

    if (x == 0 || x == 1) return x;
    if (x == -1) return (N & 1) == 1 ? -1 : 1;

    if (N < 0) {
        x = 1 / x;
        N = -N;
    }

    long long i;
    double tmp = x, ans = 1.0;
    /* i/=2优化成位运算i>>=1 */
    for (i = N; i > 0; i >>= 1) {
        /* n%2==1 可以优化成(n&1)==1 进一步优化成i&1 */
        if (i & 1) ans *= tmp;
        tmp *= tmp;
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    double y = recursive_mypow(1.2, 19);
    printf("%f\n", y);
    return 0;
}
