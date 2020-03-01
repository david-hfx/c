/**
 * @Author: David
 * @Date: 2020-02-21 00:08:57
 * @Description:二分查找的C语言实现
 */

/*
在实际代码中，可以去掉测试，不修改源代码，加上这一行就行,或者在编译时加上-DNDEBUG
 */

// #define NDEBUG
#include <assert.h> /* assert */
#include <stdio.h>  /* printf */
#define N 6

/**
 * @description: 测试函数，arr是否为已排序的数组
 */
int is_sorted(int arr[], int low, int high) {
    int i;
    for (i = low; i < high - 1; i++) {
        if (arr[i + 1] < arr[i]) return 0;
    }
    return 1;
}

/**
 * @description: 二分查找，arr[low,high+1]为排序好的数组，num为要查找的数
 * @param int* arr 要查找的数组
 * @param int low arr的下界
 * @param int high arr的上界
 * @param int num 要查找的数字
 * @return: num在arr中的索引（下标）
 */
int binary_search(int arr[], int low, int high, int num) {
    int mid;
    while (low <= high) {
        assert(is_sorted(arr, low, high)); /* 断言 */
        mid = (low + high) / 2;
        if (num < arr[mid])
            high = mid - 1;
        else if (num > arr[mid])
            low = mid + 1;
        else {
            /* 确保返回的是num在arr中出现的第一个位置，有特殊需求可加 */
            int i = mid - 1;
            while (arr[i] == arr[mid]) --i;
            return i + 1;
        }
    }
    return -1;
}

int main(int argc, char const *argv[]) {
    int arr[N] = {3, 3, 3, 3, 8, 10};
    int idx = binary_search(arr, 0, N, 3);
    printf("%d\n", idx);
    return 0;
}
