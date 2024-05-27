#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <vector <int>> res;
vector <int> temp;
vector <int> num;
int n;

void recursion(int index) {
    if (index == n) {
        res.push_back(temp);
        return;
    }
    temp.push_back(num[index]);
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
    int t;
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        num.push_back(t);
    }
    recursion(0);
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
沿用上一题思路即可
*/