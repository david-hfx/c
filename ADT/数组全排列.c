#include <stdio.h>  /* printf */
#include <stdlib.h> /* srand rand */
#include <time.h>   /* time */

/* 交换两个元素 */
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
 *@功能: 打印数组的全排列
 *@param1: arr为要全排列的数组
 *@param2: begin数组的起始位置
 *@param3: end数组的末位置
 */
void fullpermutation(int arr[], int begin, int end) {
    int i;
    // 找到一个排列就打印
    if (begin >= end) {
        for (i = 0; i < end; i++) printf("%d ", arr[i]);
        printf("\n");
    } else {
        for (i = begin; i < end; i++) {
            if (begin != i) swap(&arr[begin], &arr[i]);
            //递归排列剩余的从begin+1到end的元素
            fullpermutation(arr, begin + 1, end);
            //回溯时还原
            if (begin != i) swap(&arr[begin], &arr[i]);
        }
    }
}

/*
 *@功能: 从arr[n]中随机取m个元素
 *@param1: arr原数组
 *@param2: n——arr数组的长度
 *@param3: a——返回数组
 *@param4: m——数组a的长度
 */
void mfromn(int arr[], int n, int a[], int m) {
    int i, j = m;
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        if (rand() % (n - i) < j) {  // 保证从arr[n]中取出m个数
            a[m - j] = arr[i];  // i在变化，保证a[m]取得都是arr中不同的数
            j--;
        }
    }
}
/*
 *@功能: arr[arr_len]中取NUM个数的组合
 *@param1: arr为原始数组
 *@param2: start为遍历起始位置
 *@param3: result保存索引结果，为一维数组
 *@param4: count为result数组的索引值，起辅助作用
 *@param5: NUM为要选取的元素个数
 *@param6: arr_len为原始数组的长度，为定值
 */
void combine(int arr[], int start, int result[], int count, const int NUM,
             const int arr_len) {
    int i;
    //确保最后一个元素加后面的元素为要选取的元素个数
    for (i = start; i < arr_len + 1 - count; i++) {
        result[count - 1] = i;
        if (count - 1 == 0) {
            int j;
            for (j = NUM - 1; j >= 0; j--) printf("%d\t", arr[result[j]]);
            printf("\n");
        } else
            combine(arr, i + 1, result, count - 1, NUM, arr_len);
    }
}

int main(int argc, char const* argv[]) {
    // int arr[5] = {1, 2, 3, 4, 5};
    // int a[3];
    // mfromn(arr, 5, a, 3);
    // for (int i = 0; i < 3; i++) {
    //     printf("%d\n", a[i]);
    // }
    int arr[] = {4, 3, 5, 6, 7};
    int num = 3;
    int result[num];

    combine(arr, 0, result, num, num, sizeof(arr) / sizeof(arr[0]));
    return 0;
}
