#include <stdio.h>  /* scanf printf getchar */
#include <stdlib.h> /* srand rand */
#include <time.h>   /* time */

int main(int argc, char const *argv[]) {
    char gesture[3][10] = {"scissor", "stone", "cloth"};
    int man, computer, result, ret;

    srand(time(NULL));  //设置随机种子
    while (1) {
        computer = rand() % 3;
        printf("\nInput your gesture (0-scissor 1-stone 2-cloth):\n");
        ret = scanf("%d", &man);
        if (ret != 1 || man < 0 || man > 2) {
            printf("Invid input! Please input 0, 1 or 2.\n");
            while (getchar() != '\n')  //防止输入字符出现无限循环
                ;
            continue;
        }
        printf("Your gesture: %s\tComputer gesture: %s\n", gesture[man],
               gesture[computer]);

        //剪刀石头布相生相克，形成一个环，凡是具有环的特性的数学模型都可以考虑取模运算
        //先确定man-computer和%3,再补足其他常数得到normalized的结果
        result = (man - computer + 4) % 3 - 1;
        if (result == 0)
            printf("You win!\n");
        else if (result == 1)
            printf("Draw!\n");
        else
            printf("You lose!\n");
    }
    return 0;
}
