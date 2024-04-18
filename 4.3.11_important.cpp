#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef struct points{
    int x;
    int y;
}p;

bool cmp (p a, p b) {
    return (a.x != b.x ? a.x < b.x : a.y < b.y);
}

vector <p> datas;

void recursion (int n, int x, int y, int cx, int cy) {
    if (n == 1) {
        return;
    }
    else {
        int h = n / 2;
        //判断当前区域是否有特殊方格
        //如果有，则可以得出此轮所需要覆盖的骨牌的坐标,并且继续划分这部分
        if (x + h > cx && y + h > cy) {
            p now;
            now.x = x + h;
            now.y = y + h;
            datas.push_back(now);
            recursion(h, x, y, cx, cy);
        }
        //如果没有，需要设置一个特殊方格，该方格坐标为与其它三个区域交界的位置，作为后续划分的特殊方格使用，并继续划分这部分，但需要更新cx，cy
        else {
            recursion(h, x, y, x + h - 1, y + h - 1);
        }
        if (x + h > cx && y + h <= cy) {
            p now;
            now.x = x + h;
            now.y = y + h - 1;
            datas.push_back(now);
            recursion(h, x, y + h, cx, cy);
        }
        else {
            recursion(h, x, y + h, x + h - 1, y + h);
        }
        if (x + h <= cx && y + h > cy) {
            p now;
            now.x = x + h - 1;
            now.y = y + h;
            datas.push_back(now);
            recursion(h, x + h, y, cx, cy);
        }
        else {
            recursion(h, x + h, y, x + h, y + h - 1);
        }
        if (x + h <= cx && y + h <= cy) {
            p now;
            now.x = x + h - 1;
            now.y = y + h - 1;
            datas.push_back(now);
            recursion(h, x + h, y + h, cx, cy);
        }
        else {
            recursion(h, x + h, y + h, x + h, y + h);
        }
    }
}

int main () {
    int n;
    scanf ("%d", &n);
    int cx, cy;
    scanf("%d %d", &cx, &cy);
    recursion(n, 1, 1, cx, cy);
    sort(datas.begin(), datas.end(), cmp);
    for (int i = 0; i < datas.size(); i++) {
        printf ("%d %d\n", datas[i].x, datas[i].y);
    }
    system("pause");
    return 0;
}

/*
这题我真是一点思路都没有

该题的思路主要是将一个规模为n的问题分解为k个规模较小的子问题，就本题具体而言，则是将大正方形划分为四个相同的小正方形
而特殊方格必定位于这四个小正方形其中一个里面，另外三个则没有，故要将另外三个也变成含有一个特殊方格的小正方形，只需要在交界处加一块L形即可
递归地使用这种分割方法，直到剩下1*1的棋盘
*/