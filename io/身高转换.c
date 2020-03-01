#include <stdio.h> /* printf scanf */

int main(int argc, char const* argv[]) {
    printf(
        "请分别输入身高的英尺和英寸，"
        "如输入\"5 7\"表示身高5英尺7英寸：");
    double foot;
    double inch;
    scanf("%lf %lf", &foot, &inch);
    printf("您的身高是%.2f米\n", ((foot + inch / 12.) * 0.3048));
    return 0;
}
