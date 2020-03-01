#include <stdio.h> /* printf */
#define N 5

/**
 * @description:将arr[low:high+1]划分为两段，使左边均小于右边，并返回临界索引
 * @param int* arr 要划分的数组
 * @param int low 数组起始位置
 * @param int high 数组末位置
 * @return:临界索引
 */
int partition(int arr[], int low, int high) {
    int pivot = arr[low];

    while (low < high) {
        while (low < high && arr[high] >= pivot) high--;
        arr[low] = arr[high];
        while (low < high && arr[low] <= pivot) low++;
        arr[high] = arr[low];
    }

    arr[low] = pivot;
    return low;
}

/**
 * @description: 返回arr[low:high+1]中的第k小元素
 * @param int* arr 要寻找的数组
 * @param int low arr的起始位置
 * @param int high arr的末位置
 * @param int k 第k小元素
 * @return:
 */
int order_statistic(int arr[], int low, int high, int k) {
    int mid;
    if (low <= high) {
        mid = partition(arr, low, high);
        /* k与索引差一个1 */
        if (k - 1 == mid)
            return arr[mid];
        else if (k - 1 < mid)
            return order_statistic(arr, low, mid - 1, k);
        else
            return order_statistic(arr, mid + 1, high, k);
    }
}

int main(int argc, char const *argv[]) {
    int arr[N] = {5, 3, 6, 1, 7};
    int k = order_statistic(arr, 0, N - 1, 5);
    printf("%d\n", k);
    return 0;
}
