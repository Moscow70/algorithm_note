#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    int n;
    scanf("%d", &n);
    int res[100001] = {0};
    int name = 0;
    int points = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &name, &points);
        res[name] = res[name] + points;
    }
    int max = 0;
    int maxid = 1;
    for (int i = 1; i <= n; i++) {
        if (res[i] > max) {
            max = res[i];
            maxid = i;
        }
    }
    printf("%d %d", maxid, max);
    return 0;
}

/*
本题若为0，也应该是第一个学校分数最高，故应该输出1 0而非0 0，注意初始条件
*/