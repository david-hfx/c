/*
 * @Author: David
 * @Date: 2020-02-25 21:57:12
 * @Github: https://github.com/david-hfx
 * @Description:利用深度优先搜索（dfs）解决迷宫问题
 */
#include "main.h"  /* MAX_ROW MAX_COL sp*/
#include "maze.h"  /* maze print_maz() */
#include "stack.h" /* stack push pop is_empty */
#include <stdio.h> /* printf putchar */

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
        if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1)
            break;
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
