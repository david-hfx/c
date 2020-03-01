/*
 * @Author: David
 * @Date: 2020-02-20 16:31:32
 * @Description:归并排序c语言实现
 */
#include <stdio.h>  /* printf */
#include <stdlib.h> /* malloc free */
#define N 7

void merge(int arr[], int start, int mid, int end);
void merge2(int arr[], int start, int mid, int end);
void sort(int arr[], int start, int end);
void print_arr(int arr[], int len);

int main(int argc, char const* argv[]) {
    int arr[N] = {5, 3, 2, 7, 8, 10, 6};
    print_arr(arr, N);
    sort(arr, 0, N - 1);
    print_arr(arr, N);
    return 0;
}

void print_arr(int arr[], int len) {
    int i;
    for (i = 0; i < len; i++) printf("%d ", arr[i]);
    printf("\n");
}

/**
 * @description: 将数组arr[start:end]进行归并排序
 * @param int arr 要排序的数组
 * @param int start 数组起始位置
 * @param int end 数组结束位置 len(arr)-1
 * @return:void
 */
void sort(int arr[], int start, int end) {
    int mid;
    if (start < end) {
        mid = (start + end) / 2;
        sort(arr, start, mid);
        sort(arr, mid + 1, end);
        merge2(arr, start, mid, end);
    }
}

/**
 * @description:将两个已排序好的数组合并 arr[start:mid], arr[mid+1,end]
 * @param int arr 要排序的数组
 * @param int start 排序起始位置
 * @param int mid 排序中间位置
 * @param int end 排序结束位置
 * @return:void
 */
void merge(int arr[], int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int left[n1], right[n2]; /* C99 可变长数组 */
    int i, j, k;

    for (i = 0; i < n1; i++) left[i] = arr[start + i];
    for (j = 0; j < n2; j++) right[j] = arr[mid + 1 + j];

    i = j = 0;
    k = start;
    while (i < n1 && j < n2)
        if (left[i] < right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];

    while (i < n1) arr[k++] = left[i++];
    while (j < n2) arr[k++] = right[j++];
}

/**
 * @description: merge函数的另一种实现
 * @param same as merge
 * @return:
 */
void merge2(int arr[], int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int* tmp = (int*)malloc((end - start + 1) * sizeof(int));

    int ll = start, lh = mid, rl = mid + 1, rh = end;

    int i, j;
    /* 双指针移动 */
    for (i = 0; ll <= lh && rl <= rh; i++) {
        if (arr[ll] <= arr[rl])
            tmp[i] = arr[ll++];
        else
            tmp[i] = arr[rl++];
    }

    /* 如果有剩余，则补足 */
    if (ll <= lh)
        for (j = ll; j <= lh; j++) tmp[i++] = arr[j];

    if (rl <= rh)
        for (j = rl; j <= rh; j++) tmp[i++] = arr[j];

    for (i = start; i <= end; i++) arr[i] = tmp[i - start];
    free(tmp);
}