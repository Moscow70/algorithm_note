#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

const int MAXN = 729;

char map[MAXN][MAXN];

void recursion(int n, int x, int y) {
    if (n == 0) {
        return;
    }
    else if (n == 1) {
        map[x][y] = 'X';
    }
    else {
        recursion(n - 1, x, y);
        recursion(n - 1, x, y + 2 * (int)pow(3.0, n - 2));
        recursion(n - 1, x + (int)pow(3.0, n - 2), y + (int)pow(3.0, n - 2));
        recursion(n - 1, x + 2 * (int)pow(3.0, n - 2), y);
        recursion(n - 1, x + 2 * (int)pow(3.0, n - 2), y + 2 * (int)pow(3.0, n - 2));
    }

}

int main () {
    int n;
    scanf("%d", &n);
    memset(map, ' ', sizeof(map));
    recursion(n, 0, 0);
    for (int i = 0; i < (int)pow(3.0, n - 1); i++) {
        for (int j = 0; j < (int)pow(3.0, n - 1); j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}

/*
这题还有边长相同这个条件，所以要保证横向边等于纵向边，就可以确定中间要打几个空格，从本题的规律来看，边长为是3^(n-1)
而由于不可能将光标跳回第一行输出，故本题仍然需要借助二维数组来存储信息，之后再统一输出
*/