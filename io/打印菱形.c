#include <stdio.h>  /* printf */
#include <stdlib.h> /* abs */

void diamond(int n, char a) {
    if (n % 2 == 0) {
        printf("n should be an odd.\n");
        return;
    }
    int i, j;
    for (i = 1; i <= n / 2; i++) {
        for (j = 1; j <= n / 2 - i + 1; j++) printf("  ");
        for (j = 1; j <= 2 * i - 1; j++) printf("%c ", a);
        // for (j = 1; j <= n / 2 - i + 1; j++) printf("  ");
        printf("\n");
    }
    for (j = 1; j <= n; j++) printf("%c ", a);
    printf("\n");
    for (i = n / 2; i >= 1; i--) {
        for (j = 1; j <= n / 2 - i + 1; j++) printf("  ");
        for (j = 1; j <= 2 * i - 1; j++) printf("%c ", a);
        // for (j = 1; j <= n / 2 - i + 1; j++) printf("  ");
        printf("\n");
    }
}

void diamond2(int n, char a) {
    int x, y;
    for (y = n / 2; y >= -n / 2; y -= 1) {
        for (x = -n / 2; x <= n / 2; x += 1) {
            putchar(abs(x) + abs(y) <= n / 2 ? a : ' ');
            putchar(' ');
        }

        putchar('\n');
    }
}

int main(int argc, char const *argv[]) {
    diamond2(10, '+');
    return 0;
}
