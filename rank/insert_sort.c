/*
 * @Author: David
 * @Date: 2020-02-20 14:48:53
 * @Description:插入排序实现，insert_arr(int*,int)为插入排序算法实现函数
 */

#include <stdio.h> /* printf */

#define N 5

/**
 * @description:插入排序的思想是向已排序好的数组中插入一个数，依次向前比较，如果当前数
 * 大于之前数，则排序结束，如果小于之前数，则将之前数向后移动，直到找到小于当前数的数
 * @param array a 要排序的数组
 * @param int len 数组长度
 * @return: void
 */
void insert_sort(int arr[], int len) {
    int i, j, key;
    for (i = 1; i < len; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            /* 依次与前面比较，如果大于当前值，就把大值放在后面 */
            arr[j + 1] = arr[j];
            j--;
        }
        /* 将原来的值放在比其值小的后面 */
        arr[j + 1] = key;
    }
}

void print_arr(int arr[], int len) {
    int i;
    for (i = 0; i < len; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main(int argc, char const *argv[]) {
    int a[N] = {4, 3, 2, 6, 10};

    print_arr(a, N);
    insert_sort(a, N);
    print_arr(a, N);

    return 0;
}
