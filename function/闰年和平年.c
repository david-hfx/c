#include <stdio.h> /* printf scanf */

int is_leap_year(int year) {
    if (year <= 0) {
        return -1;
    }
    if (year % 400 == 0) {
        return 1;
    } else if (year % 4 == 0 && year % 100 != 0) {
        return 1;
    } else {
        return 0;
    }
}

int main(int argc, char const* argv[]) {
    printf("请输入年份,输入q结束：");
    int year;
    while (scanf("%d", &year)) {
        if (is_leap_year(year)) {
            printf("%d年是闰年.\n", year);
        } else {
            printf("%d年是平年.\n", year);
        }
    }
    return 0;
}
