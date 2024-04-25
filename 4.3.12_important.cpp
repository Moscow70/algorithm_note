#include <stdio.h>
#include <iostream>

using namespace std;

int now = 1;
const int MAXN = 25;
int matrix[MAXN][MAXN] = {0};

void recursion (int n, int x, int y) {
    if (n == 0) {
        return;
    }
    else if (n == 1) {
        matrix[x][y] = now;
        now++;
    }
    else {
        for (int j = y; j < n - 1 + y; j++) {
            matrix[x][j] = now;
            now++;
        }
        for (int i = x; i < n - 1 + x; i++) {
            matrix[i][n - 1 + y] = now;
            now++;
        }
        for (int j = n - 1 + y; j > y; j--) {
            matrix[n - 1 + x][j] = now;
            now++;
        }
        for (int i = n - 1 + x; i > x; i--) {
            matrix[i][y] = now;
            now++;
        }
        recursion(n - 2, x + 1, y + 1);
    }
}

int main () {
    int n;
    scanf("%d", &n);
    recursion(n, 0, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", matrix[i][j]);
            if (j != n - 1) {
                printf (" ");
            }
        }
        printf("\n");
    }
    system("pause");
    return 0;
}

/*
这题就是要找到每一圈的规律，然后每次迭代都是一圈，计算完之后再走下一圈
*/