#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main () {
    int n;
    char c;
    scanf("%d %c", &n, &c);
    int row = 0;
    int total = 0;
    int i = 1;
    int len = 0;
    if (n != 0) {
        total = 1;
        row = 1;
        if (n != 1) {
            while (total < n) {
                total = total + 2 * (2 * i + 1);
                row = row + 2;
                i++;
            }
            i--;
            row = row - 2;
            total = total - 2 * (2 * i + 1);
        }
        row = (row + 1) / 2;
        len = 2 * row - 1;
        int nowlen = len;
        int j = 0;
        for (int i = 0; i < row; i++) {
            for (j = 0; j < i; j++) {
                printf(" ");
            }
            for (j = i; j < nowlen + i; j++) {
                printf("%c", c);
            }
            for (j = i + nowlen; j < len; j++) {
                // printf(" ");
            }
            if (j == len) {
                printf("\n");
            }            
            nowlen = nowlen - 2;
        }
        nowlen = nowlen + 4;
        for (int i = 1; i < row; i++) {
            for (j = 0; j < row - i - 1; j++) {
                printf(" ");
            }
            for (j = row - i - 1; j < nowlen + row - i - 1; j++) {
                printf("%c", c);
            }
            for (j = row - i - 1 + nowlen; j < len; j++) {
                // printf(" ");
            }
            if (j == len) {
                printf("\n");
            }            
            nowlen = nowlen + 2;
        }
    }
    printf("%d\n", n - total);
    return 0;
}

/*
自己写的这个有点麻烦，明天看看答案
感觉也差不多，答案就是先根据公式算出底边为多少
*/