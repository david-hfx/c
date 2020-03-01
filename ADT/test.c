#include <stdio.h> /* printf */

enum coordinate_type { RECTANGULAR = 1, POLAR };

int main(void) {
    // enum中的RECTANGULAR为全局变量，此处为局部变量，默认值为0
    int RECTANGULAR;
    printf("%d %d\n", RECTANGULAR, POLAR);  // 0 2
    return 0;
}
