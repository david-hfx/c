/*
 *取余运算按照(a/b)*b+a%b=a以及Truncate Toward Zero原则，a%b的结果总是和a同号
 */
#include <stdio.h> /* printf */

int main(int argc, char const* argv[]) {
    int a = 10, b = -3;
    int c = -10, d = 3;
    printf("%d/%d=%d,%d%%%d=%d\n", a, b, a / b, a, b, a % b);
    printf("%d/%d=%d,%d%%%d=%d\n", c, d, c / d, c, d, c % d);
    return 0;
}
