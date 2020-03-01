/*
 * @Author: David
 * @Date: 2020-02-26 23:34:21
 * @Github: https://github.com/david-hfx
 * @Description:用递归dfs解决迷宫问题,找到最短路径并打印
 */
#include <stdio.h>    /* printf putchar */
#define MAX_ROW 5     /* 迷宫最大行 */
#define MAX_COL 5     /* 迷宫列 */
#define STACK_SIZE 50 /* 堆栈最大长度 */

/* 结构体，存储坐标 */
typedef struct point {
    int row, col;
} sp;

int min = 50; /* 记录最小步数 */

/* 栈声明和栈方法实现 */
sp stack[STACK_SIZE], cpy[STACK_SIZE]; /* 栈 和 保存栈的数组 */
int top = 0;

void push(sp p) { stack[top++] = p; }

sp pop(void) { return stack[--top]; }

int is_empty(void) { return top == 0; }

void reverse_stack() {
    for (int i = top - 1; i >= 0; i--) {
        cpy[i] = pop();
    }
}

/* 迷宫，0代表可走，1代表墙壁 */
int maze[MAX_ROW][MAX_COL] = {{0, 1, 0, 0, 0},
                              {0, 1, 0, 1, 0},
                              {0, 0, 0, 0, 0},
                              {0, 1, 1, 1, 0},
                              {0, 0, 0, 1, 0}};

/* 记录走的方位，分别为下、左、右、上 */
sp go[4] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};

/* 打印迷宫 */
void print_maze(void) {
    int i, j;
    for (i = 0; i < MAX_ROW; i++) {
        for (j = 0; j < MAX_COL; j++) {
            printf("%d ", maze[i][j]);
        }
        putchar('\n');
    }
    printf("*********\n");
}

void dfs(int row, int col, int step) {
    maze[row][col] = 2; /* 访问时标记为已访问 */
    sp p = {row, col};
    /* 满足条件,将坐标压入栈 */
    push(p);

    print_maze();
    /* goal 则保存步数并翻转栈（清空栈）*/
    if (row == MAX_ROW - 1 && col == MAX_COL - 1) {
        if (step < min) {
            min = step;
            reverse_stack();
        }
    }

    int i;
    for (i = 0; i < 4; i++) {
        int x = row + go[i].row;
        int y = col + go[i].col;
        if (x >= 0 && y >= 0 && x < MAX_ROW && y < MAX_COL && maze[x][y] == 0) {
            dfs(x, y, step + 1);
            maze[x][y] = 0; /* 回溯时记为未访问 */
        }
    }
    pop();
}

int main(int argc, char const *argv[]) {
    dfs(0, 0, 0);
    for (int i = 0; i <= min; i++) {
        printf("(%d, %d)\n", cpy[i].row, cpy[i].col);
    }
    return 0;
}
