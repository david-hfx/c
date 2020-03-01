#include <stdio.h>  /* printf */
#include <stdlib.h> /* malloc free */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
void dfs(int *nums, int numsSize, int *mark, int *path, int index, int **result,
         int *reIndex) {
    for (int i = 0; i < numsSize; i++) {
        if (mark[i] == 0) continue;
        mark[i] = 0;
        path[index] = nums[i];
        printf("get:%d \n", nums[i]);
        index = index + 1;

        if (index == numsSize) {
            result[*reIndex] = (int *)malloc(sizeof(int) * numsSize);
            for (int j = 0; j < numsSize; j++) {
                result[*reIndex][j] = path[j];
                printf(" %d ", path[j]);
            }
            printf("\n");
            *reIndex = *reIndex + 1;
        }

        dfs(nums, numsSize, mark, path, index, result, reIndex);
        mark[i] = 1;
        index = index - 1;
    }
}

int **permute(int *nums, int numsSize, int *returnSize,
              int **returnColumnSizes) {
    int mark[numsSize];
    for (int i = 0; i < numsSize; i++) {
        mark[i] = 1;
    }
    int path[numsSize];
    int index = 0;
    int **result = (int **)malloc(sizeof(int *) * 17000);
    int reIndex = 0;
    dfs(nums, numsSize, mark, path, index, result, &reIndex);
    *returnSize = reIndex;
    *returnColumnSizes = (int *)malloc(sizeof(int) * 17000);
    for (int i = 0; i < reIndex; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }
    return result;
}
