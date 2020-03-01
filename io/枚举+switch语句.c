#include <stdio.h> /* printf scanf */

// enum为枚举类型，week为枚举类型名，声明时为enum week +
// variableNmae，其中week可省略 typedef为定义别名，，下列语句表示day为enum
// week的别名 枚举类型默认递增1，如下列枚举代表MON=1,TUE=2,...,SUN=7
typedef enum week { MON = 1, TUE, WED, THU, FRI, SAT, SUN } day;

int main(void) {
    day day1;
    int intday1;
    printf("一周中你最喜欢？1.MON 2.TUE 3.WED 4.THU 5.FRI 6.SAT 7.SUN:\n");
    scanf("%d", &intday1);
    day1 = (day)intday1;

    switch (day1) {
        case MON:
            printf("一周中你最喜欢星期一\n");
            break;
        case TUE:
            printf("一周中你最喜欢星期二\n");
            break;
        case WED:
            printf("一周中你最喜欢星期三\n");
            break;
        case THU:
            printf("一周中你最喜欢星期四\n");
            break;
        case FRI:
            printf("一周中你最喜欢星期五\n");
            break;
        case SAT:
            printf("一周中你最喜欢星期六\n");
            break;
        case SUN:
            printf("一周中你最喜欢星期日\n");
            break;
        default:
            printf("请输入1-7内的整数.\n");
    }
    return 0;
}
