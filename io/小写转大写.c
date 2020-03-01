#include <stdio.h> /* printf */

/*
 *小写转大写
 */
int main(int argc, char const* argv[]) {
    char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                      'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                      's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    for (int i = 0; i < 26; i++) {
        if (i % 7 == 0) {
            printf("\n");
        }
        printf("%c\t", letters[i] - 32);
    }
    printf("\n");
    return 0;
}
