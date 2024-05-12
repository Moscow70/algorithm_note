#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

vector <vector <int> > res;
vector <int> temp;
int n;

void recursion(int num) {
    if (num == n) {
        res.push_back(temp);
        return;
    }
    else {
        temp.push_back(0);
        recursion(num + 1);
        temp.pop_back();
        temp.push_back(1);
        recursion(num + 1);
        temp.pop_back();
    }
}

int main () {
    scanf("%d", &n);
    recursion(0);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", res[i][j]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}

/*
虽然题目说字符串，但是可以将其转化为二维数组，不用字符串

本题思路就是在某个时刻，加入一个0，然后接上后面一段的结果（调用递归），然后换成1，接上后面一段结果，再删掉
当一直加到满足长度时就可以存储结果返回了
*/