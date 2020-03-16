#include <stdio.h>

int* swap(int* px, int* py)
{
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
    return px;
}

int main(int argc, char const* argv[])
{
    int a = 10, b = 20;
    printf("a = %d, b = %d\n", a, b);
    int* p = swap(&a, &b);
    printf("now a = %d, b = %d, *p = %d\n", a, b, *p);
    return 0;
}
