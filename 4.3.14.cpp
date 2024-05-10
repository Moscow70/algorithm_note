#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 3 * 3 * 3 * 3 * 3 * 3;
char matrix[MAXN][MAXN];

void recursion(int n, int x, int y) {
    if (n == 1) {
        matrix[x][y] = ' ';
    }
    else {
        int length = (int)pow(3.0, n - 2);
        for (int i = x + length; i < x + 2 * length; i++) {
            for (int j = y + length; j < y + 2 * length; j++) {
                matrix[i][j] = 'X';
            }
        }
        recursion(n - 1, x, y);
        recursion(n - 1, x + length, y);
        recursion(n - 1, x + 2 * length, y);
        recursion(n - 1, x, y + length);
        recursion(n - 1, x + 2 * length, y + length);
        recursion(n - 1, x, y + 2 * length);
        recursion(n - 1, x + length, y + 2 * length);
        recursion(n - 1, x + 2 * length, y + 2 * length);
    }
}

int main () {
    int n;
    scanf("%d", &n);
    int edge = (int)pow(3.0, n - 1);
    recursion(n, 0, 0);
    for (int i = 0; i < edge + 2; i++) {
        printf("+");
    }
    printf("\n");
    for (int i = 0; i < edge; i++) {
        printf("+");
        for (int j = 0; j < edge; j++) {
            printf("%c", matrix[i][j]);
        }
        printf("+");
        printf("\n");
    }
    for (int i = 0; i < edge + 2; i++) {
        printf("+");
    }
    printf("\n");
    system("pause");
    return 0;
}

/*
这个题我都没搞懂图是怎么画的
所以还是得百度，它就是一个边长为3^(n-1)的正方形，每个部分的边长再除以3，为3^(n-2)
*/