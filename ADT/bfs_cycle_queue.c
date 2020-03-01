/*
 * @Author: David
 * @Date: 2020-02-28 22:41:08
 * @Github: https://github.com/david-hfx
 * @Description:利用环形队列队列结构和bfs广度优先搜素解决迷宫问题
 */
#include <stdio.h> /* printf putchar */

#define MAX_ROW 5
#define MAX_COL 5
#define QUEUE_SIZE 10

/* 坐标点 */
typedef struct point {
    int row, col;
} sp;

sp queue[QUEUE_SIZE];
int head = 0, tail = 0;

void enqueue(sp p) {
    if (tail + 1 == QUEUE_SIZE && 0 != head) {
        tail = 0;
        queue[0] = p;
    } else {
        queue[tail++] = p;
    }
}

sp dequeue(void) {
    if (head + 1 == QUEUE_SIZE && tail != 0) {
        head = 0;
        return queue[QUEUE_SIZE - 1];
    } else {
        return queue[head++];
    }
}

int is_empty(void) { return head == tail; }

int maze[MAX_ROW][MAX_COL] = {{0, 1, 0, 0, 0},
                              {0, 1, 0, 1, 0},
                              {0, 0, 0, 0, 0},
                              {0, 1, 1, 1, 0},
                              {0, 0, 0, 1, 0}};

void print_maze(void) {
    int i, j;
    for (i = 0; i < MAX_ROW; i++) {
        for (j = 0; j < MAX_COL; j++)
            printf("%d ", maze[i][j]);
        putchar('\n');
    }
    printf("*********\n");
}

void visit(int row, int col) {
    sp visit_point = {row, col, head - 1};
    maze[row][col] = 2;
    enqueue(visit_point);
}

int main(int argc, char const *argv[]) {
    sp p = {0, 0, -1};

    maze[p.row][p.col] = 2;
    enqueue(p);

    while (!is_empty()) {
        p = dequeue();
        if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1)
            break;
        if (p.row + 1 < MAX_ROW && maze[p.row + 1][p.col] == 0)
            visit(p.row + 1, p.col);
        if (p.col + 1 < MAX_COL && maze[p.row][p.col + 1] == 0)
            visit(p.row, p.col + 1);
        if (p.row - 1 >= 0 && maze[p.row - 1][p.col] == 0)
            visit(p.row - 1, p.col);
        if (p.col - 1 >= 0 && maze[p.row][p.col - 1] == 0)
            visit(p.row, p.col - 1);
        print_maze();
    }

    if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1) {
        printf("Exist path!\n");
    } else {
        printf("No path!\n");
    }

    return 0;
}
