/*
 * @Author: David
 * @Date: 2020-02-20 23:15:21
 * @Description:快速排序C语言实现
 */
#include <stdio.h> /* printf */
#define N 6

int partition(int arr[], int start, int end);
void quicksort(int arr[], int start, int end);
void print_arr(int arr[], int len);

int main(int argc, char const *argv[]) {
    int a[N] = {4, 3, 5, 7, 6, 8};
    print_arr(a, N);
    quicksort(a, 0, N - 1);
    print_arr(a, N);
    return 0;
}

void print_arr(int arr[], int len) {
    int i;
    for (i = 0; i < len; i++) printf("%d ", arr[i]);
    printf("\n");
}

/**
 * @description:将arr[start:end+1]划分为两段，使左边均小于右边，并返回临界索引
 * @param int* arr 要划分的数组
 * @param int start 数组起始位置
 * @param int end 数组末位置
 * @return:临界索引
 */
int partition(int arr[], int start, int end) {
    int pivot = arr[start];
    int i;
    /* start和end做双指针 */
    while (start < end) {
        /* 注意while内条件，如果仅有arr[end] >= pivot，有可能造成start > end */
        while (start < end && arr[end] >= pivot) end--;
        /* 找到一个小于pivot的值的就令start指针指向该值 */
        arr[start] = arr[end];
        while (start < end && arr[start] <= pivot) start++;
        /* 找到一个大于pivot的值的就令end指针指向该值 */
        arr[end] = arr[start];
    }
    /* 排序完start = end,令arr[start]=arr[end]=pivot返回 */
    arr[start] = pivot;
    return start;
}

/**
 * @description: 快速排序，递归
 * @param same as partition
 * @return: void
 */
void quicksort(int arr[], int start, int end) {
    int mid;
    if (start < end) {
        mid = partition(arr, start, end);
        quicksort(arr, start, mid);
        quicksort(arr, mid + 1, end);
    }
}