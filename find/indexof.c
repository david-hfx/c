/*
 * @Author: David
 * @Date: 2020-02-20 23:18:40
 * @Description:求解字符在字符串中出现的位置
 */
#include <stdio.h> /* printf */
#define N 20

/**
 * @description: 返回字符letter在string中首次出现的位置索引
 * @param char letter 要查找的字符
 * @param char* string 要查找的字符串
 * @return: 字符所在字符串的首次索引
 */
int indexof(char letter, char string[]) {
    int i = 0;
    /* 字符串可以根据最后一个字符为'\0'的特性，不用输入长度 */
    while (string[i] != '\0') {
        if (string[i] == letter) return i;
        ++i;
    }
    return -1;
}

int main(int argc, char const *argv[]) {
    char string[N] = "hello world";
    char letter = 'o';
    int idx = indexof(letter, string);
    printf("\'%c\'是\"%s\"中的第%d个字母\n", letter, string, idx + 1);
    return 0;
}