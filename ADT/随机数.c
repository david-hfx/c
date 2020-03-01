#include <stdio.h>  /* printf */
#include <stdlib.h> /* srand rand */
#include <time.h>   /* time */

#define max(a, b) (((a) > (b)) ? (a) : (b))  //利用宏实现max函数
#define N 20                                 //数组长度
#define UPPER_BOUND 10                       //数组上界

/*
 *生成一个从a[n]数组，数组所有元素为0~upper_bound之间的随机数
 */
void gen_random(int* a, int n, int upper_bound) {
    int i;
    srand(time(NULL));  // 以当前时间为种子，生成随机数
    for (i = 0; i < n; i++) a[i] = rand() % upper_bound;
}

/*
 *打印数组
 */
void print_array(int* a, int n) {
    int i;
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

/*
 *计算数组a中value值的数量
 */
int howmany(int* a, int n, int value) {
    int i, count = 0;
    for (i = 0; i < n; i++)
        if (a[i] == value) ++count;
    return count;
}

/*
 *数组a中的最大值
 */
int max_of_array(int* a, int len) {
    int i;
    int maxN = a[0];
    for (i = 1; i < len; i++) maxN = max(maxN, a[i]);
    return maxN;
}

int main(int argc, char const* argv[]) {
    int a[N];

    gen_random(a, N, UPPER_BOUND);

    //直方图求值
    int i, j;
    int histogram[UPPER_BOUND] = {0};
    for (i = 0; i < N; i++) {
        histogram[a[i]]++;
    }
    print_array(histogram, UPPER_BOUND);

    // 打印直方图
    int row = max_of_array(a, UPPER_BOUND);
    for (i = 0; i < UPPER_BOUND; i++) printf("%d ", i);
    putchar('\n');
    for (i = 0; i < row; i++) {
        for (j = 0; j < UPPER_BOUND; j++) {
            putchar(histogram[j]-- > 0 ? '*' : ' ');
            putchar(' ');
        }
        putchar('\n');
    }
    return 0;
}
