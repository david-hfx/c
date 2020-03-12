/*
 * @Author: David
 * @Date: 2020-02-24 21:17:51
 * @Github: https://github.com/david-hfx
 * @Description:逆序打印
 */

#include <stdio.h> /* printf */
#define LEN 3

char buf[LEN] = {'a', 'b', 'c'};

void print_backward(int pos) {
    if (pos == LEN)
        return;

    print_backward(pos + 1);
    printf("%c\d", buf[pos]);
}

int main(int argc, char const *argv[]) {
    print_backward(0);
    return 0;
}
