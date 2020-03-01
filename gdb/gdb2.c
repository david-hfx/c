#include <stdio.h> /* printf scanf */

int main(int argc, char const *argv[]) {
    int sum, i;
    char input[5];

    while (1) {
        sum = 0;
        scanf("%s", input);
        for (i = 0; input[i] != '\0'; i++) {
            if (input[i] < '0' || input[i] > '9') {
                printf("Invalid input!\n");
                sum = -1;
                break;
            }
            sum = sum * 10 + input[i] - '0';
        }
        printf("input=%d\n", sum);
    }

    return 0;
}
