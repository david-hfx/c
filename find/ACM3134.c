/*
 * @Author: David
 * @Date: 2020-02-24 19:53:30
 * @Description:ACM3134题，求
 */
#include <stdio.h>
#define max(A, B) (A > B ? A : B)

int n, dep, num[15];

// x是上一次操作之后得到的最大的数
int dfs(int cnt, int x) {
    if (num[cnt] == n) return 1;

    if (cnt >= dep) return 0;

    x = max(x, num[cnt]);

    if (x * (1 << (dep - cnt)) < n)
        return 0;  //如果最大的数都不能得到n就直接返回

    for (int i = 0; i <= cnt; i++) {
        num[cnt + 1] = num[cnt] + num[i];

        if (dfs(cnt + 1, x)) return 1;

        if (num[cnt] > num[i])
            num[cnt + 1] = num[cnt] - num[i];
        else
            num[cnt + 1] = num[i] - num[cnt];

        if (dfs(cnt + 1, x)) return 1;
    }

    return 0;
}

int main(void) {
    while (~scanf("%d", &n) && n) {
        if (n == 1)
            printf("0\n");
        else {
            num[0] = 1;

            for (dep = 1;; dep++) {
                if (dfs(0, 1)) break;
            }

            printf("%d\n", dep);
        }
    }
}
