#include <stdio.h> /* printf scanf */

double myround(double x) {
    if (x >= 0) {
        x = (int)(x + 0.5);
    } else {
        x = -(int)(-x + 0.5);
    }
    return (double)x;
}

int main(int argc, char const* argv[]) {
    double x;
    printf("请输入一个小数：");
    scanf("%lf", &x);
    printf("%.2f四舍五入结果为%.1f\n", x, myround(x));
    return 0;
}
