#include <stdio.h> /* scanf printf */

int ceil1(float);
int floor1(float);

int main(int argc, char const* argv[]) {
    printf("请输入一个小数：");
    float f;
    scanf("%f", &f);
    printf("⌊x⌋=%d,", floor1(f));
    printf("⌈x⌉=%d.\n", ceil1(f));
    return 0;
}

int ceil1(float a) {
    if (a == floor1(a)) {
        return a;
    } else {
        return floor1(a) + 1;
    }
}

int floor1(float a) { return (int)a; }
