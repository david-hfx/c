#include <stdio.h> /* printf */

void increment(int* a) { *a = *a + 1; }

int main(int argc, char const* argv[]) {
    int a = 5;
    increment(&a);
    printf("%d\n", a);
    return 0;
}
