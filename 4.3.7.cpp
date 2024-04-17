#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <vector <int>> num;
int layer;

int recursion(int row, int col) {
    if (row == layer - 1) {
        return num[row][col];
    }
    else {
        return max(recursion(row + 1, col), recursion(row + 1, col + 1)) + num[row][col];
    }
}

int main () {

    scanf("%d", &layer);
    vector <int> thislayer;
    for (int i = 0; i < layer; i++) {
        thislayer.clear();
        for (int j = 0; j <= i; j++) {
            int temp;
            cin >> temp;
            thislayer.push_back(temp);
        }
        num.push_back(thislayer);
    }
    int res;
    res = recursion(0, 0);
    printf("%d", res);
    system("pause");
    return 0;
}

/*
注意一下全局变量的运用和递归算法的写法
*/