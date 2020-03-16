#include <stdio.h>

int main(int argc, char const* argv[])
{
    int i;
    /* argv[i]!=NULL 可以替换成i<arf=gc */
    for (i = 0; argv[i] != NULL; i++) {
        printf("argv[%d]=%s\n", i, argv[i]);
    }
    return 0;
}
