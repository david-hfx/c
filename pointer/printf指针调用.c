#include <stdio.h>

int main(int argc, char const* argv[])
{
    const char* p = "abcd";
    const char str1[] = "abcd";
    char str2[5] = "abcd";
    printf(p);
    printf(str1);
    printf(str2);
    printf("abcd");
    return 0;
}
