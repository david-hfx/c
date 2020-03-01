#include <stdio.h> /* printf scanf */

void print_day(int day) {
    char days[8][10] = {"",         "Monday", "Tuesday",  "Wednesday",
                        "Thursday", "Friday", "Saturday", "Sunday"};
    if (day < 1 || day > 7) printf("illegal day number.\n");
    printf("Today is %s.\n", days[day]);
}

int main(int argc, char const *argv[]) {
    int day;
    printf("please enter today number(1-7): ");
    scanf("%d", &day);
    print_day(day);
    return 0;
}
