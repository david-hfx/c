/*
 * @Author: David
 * @Date: 2020-03-13 00:16:04
 * @Github: https://github.com/david-hfx
 * @Description:打印字符r，如何用指针找到
 */
#include <stdio.h> /* printf */

int main(int argc, char const* argv[])
{
    char a[4][3][2] = { { { 'a', 'b' }, { 'c', 'd' }, { 'e', 'f' } },
        { { 'g', 'h' }, { 'i', 'j' }, { 'k', 'l' } },
        { { 'm', 'n' }, { 'o', 'p' }, { 'q', 'r' } },
        { { 's', 't' }, { 'u', 'v' }, { 'w', 'x' } } };
    char(*pa)[2] = &a[1][0];
    char(*ppa)[3][2] = &a[1];
    printf("%c %c\n", (*(pa + 5))[1], ppa[1][2][1]);
    return 0;
}
