#include <stdio.h> /* printf */

// 有理数结构体，分子和分母
typedef struct rational {
    int x, y;
} rt;

// 打印有理数结构体
void print_rational(rt z) { printf("%d/%d\n", z.x, z.y); }

// 求分子分母最大公约数
int gcd(int a, int b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

// 分子分母约简
void simplify(int* a, int* b) {
    int gcdiv = gcd(*a, *b);
    *a = *a / gcdiv;
    *b = *b / gcdiv;
}

// 构造函数，根据分子分母构造有理数结构体
rt make_rational(int molecular, int denominator) {
    rt z;
    simplify(&molecular, &denominator);
    z.x = molecular;
    z.y = denominator;
    return z;
}

// 有理数四则运算
rt add_rational(rt z1, rt z2) {
    rt z;
    int molecular = z1.x * z2.y + z1.y * z2.x;
    int denominator = z1.y * z2.y;
    simplify(&molecular, &denominator);
    z.x = molecular;
    z.y = denominator;
    return z;
}

rt sub_rational(rt z1, rt z2) {
    rt z;
    int molecular = z1.x * z2.y - z1.y * z2.x;
    int denominator = z1.y * z2.y;
    simplify(&molecular, &denominator);
    z.x = molecular;
    z.y = denominator;
    return z;
}

rt mul_rational(rt z1, rt z2) {
    rt z;
    int molecular = z1.x * z2.x;
    int denominator = z1.y * z2.y;
    simplify(&molecular, &denominator);
    z.x = molecular;
    z.y = denominator;
    return z;
}

rt div_rational(rt z1, rt z2) {
    rt z;
    int molecular = z1.x * z2.y;
    int denominator = z1.y * z2.x;
    simplify(&molecular, &denominator);
    z.x = molecular;
    z.y = denominator;
    return z;
}

int main(int argc, char const* argv[]) {
    rt z1 = make_rational(2, 3);
    rt z2 = make_rational(3, 4);

    print_rational(add_rational(z1, z2));
    print_rational(sub_rational(z1, z2));
    print_rational(mul_rational(z1, z2));
    print_rational(div_rational(z1, z2));

    return 0;
}
