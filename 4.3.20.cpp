#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cstring>

using namespace std;

vector <vector <int>> res;
vector <int> temp;
int n;


void recursion(int index) {
    if (index == n + 1) {
        res.push_back(temp);
        return;
    }
    temp.push_back(index);
    recursion(index + 1);
    temp.pop_back();
    recursion(index + 1);
}

bool cmp (vector<int> &a, vector<int> &b) {
    if (a.size() != b.size()) {
        return a.size() < b.size();
    }
    else {
        return a < b;
    }
}



int main () {
    scanf("%d", &n);
    recursion(1);
    sort(res.begin(), res.end(), cmp);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            printf("%d", res[i][j]);
            if (j != res[i].size() - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    system("pause");
    return 0;
}

/*
当index直到n+1的时候，就达到了能压入当前结果的最大值，所以将当前结果返回压入结果中。
然后每一次，都压入当前的值，并且对当前值+1进行递归；
然后删除当前的值，并且对当前值n+1进行递归，也就是把有当前值和没有当前值的情况都计算一遍
*/