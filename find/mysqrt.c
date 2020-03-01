#include <stdio.h> /* printf */
/* 绝对值 宏定义 */
#define dabs(x) ((x) > 0 ? (x) : -(x))

/**
 * @description:二分法求根号y，要求y>=1
 * @param double y
 * @return:根号y
 */
double mysqrt(double y) {
    double low = 0.0, high = y;
    double mid = -1;
    double precision = 1e-6;
    while (low < high) {
        mid = (low + high) / 2;
        if (dabs(mid * mid - y) < precision)
            break;
        else if (mid * mid - y > 0)
            high = mid - precision;
        else
            low = mid + precision;
    }
    return mid;
}

int main(int argc, char const *argv[]) {
    printf("%f\n", mysqrt(4.0));
    return 0;
}
