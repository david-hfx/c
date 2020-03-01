/*
 * @Author: David
 * @Date: 2020-02-25 21:57:12
 * @Github: https://github.com/david-hfx
 * @Description:利用深度优先搜索（dfs）解决迷宫问题
 */
#include <stdio.h> /* printf putchar */

#define MAX_ROW 5
#define MAX_COL 5

/* 结构体，存储行走路径的坐标点 */
typedef struct point {
    int row, col;
} sp;

/* 设计堆栈，push，pop和is_empty方法 */
sp stack[512];
int top = 0;

void push(sp p) { stack[top++] = p; }

sp pop(void) { return stack[--top]; }

int is_empty(void) { return top == 0; }

/* 迷宫，1代表墙壁，0代表可以走的路 */
int maze[MAX_ROW][MAX_COL] = {{0, 1, 0, 0, 0},
                              {0, 1, 0, 1, 0},
                              {0, 0, 0, 0, 0},
                              {0, 1, 1, 1, 0},
                              {0, 0, 0, 1, 0}};

/* 打印迷宫 */
void print_maze(void) {
    int i, j;
    for (i = 0; i < MAX_ROW; i++) {
        for (j = 0; j < MAX_COL; j++) printf("%d ", maze[i][j]);
        putchar('\n');
    }
    printf("*********\n");
}

/*
sp predecessor[MAX_ROW][MAX_COL] = {
    {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
    {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
    {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
    {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
    {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
};
可以将row*MAX_ROW+col结果存在predecessor数组里，用/MAX_ROW和%MAX_ROW分别取row和col，节省一半空间。
*/

/* 存储走的路径的坐标，经过优化 */
int predecessor[MAX_ROW][MAX_COL] = {{-1, -1, -1, -1, -1},
                                     {-1, -1, -1, -1, -1},
                                     {-1, -1, -1, -1, -1},
                                     {-1, -1, -1, -1, -1},
                                     {-1, -1, -1, -1, -1}};

/* visit迷宫的下一步，人走过的位置标记为2 */
void visit(int row, int col, sp pre) {
    sp visit_point = {row, col};
    maze[row][col] = 2;
    predecessor[row][col] = pre.row * MAX_ROW + pre.col;
    push(visit_point);
}

int main(int argc, char const *argv[]) {
    /* 初始化 */
    sp p = {0, 0};

    maze[p.row][p.col] = 2;
    push(p);

    while (!is_empty()) {
        p = pop();
        /* goal */
        if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1) break;
        /* right */
        if (p.col + 1 < MAX_COL && maze[p.row][p.col + 1] == 0)
            visit(p.row, p.col + 1, p);
        /* down */
        if (p.row + 1 < MAX_ROW && maze[p.row + 1][p.col] == 0)
            visit(p.row + 1, p.col, p);
        /* up */
        if (p.row - 1 >= 0 && maze[p.row - 1][p.col] == 0)
            visit(p.row - 1, p.col, p);
        /* left */
        if (p.col - 1 >= 0 && maze[p.row][p.col - 1] == 0)
            visit(p.row, p.col - 1, p);
        print_maze();
    }
    if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1) {
        printf("(%d, %d)\n", p.row, p.col);
        while (predecessor[p.row][p.col] != -1) {
            int row = predecessor[p.row][p.col] / MAX_ROW;
            int col = predecessor[p.row][p.col] % MAX_ROW;
            p.row = row;
            p.col = col;
            printf("(%d, %d)\n", p.row, p.col);
        }
    } else {
        printf("No path!\n");
    }
    return 0;
}
