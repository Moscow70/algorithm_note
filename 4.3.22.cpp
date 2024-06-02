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

bool ifequal(vector<int> &a, vector<int> &b) {
    if (a.size() != b.size()) {
        return false;
    }
    else {
        if (a == b) {
            return true;
        }
        else {
            return false;
        }
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
    vector <vector <int>> resclear;
    int i = 0;
    int j = 1;
    if (!res.empty()) {
        while (j < res.size()) {
            if (!ifequal(res[i], res[j])) {
                resclear.push_back(res[i]);
                if (j == res.size() - 1) {
                    resclear.push_back(res[j]);
                }
                i++;
                j++;
            }
            else {
                while(j < res.size() && ifequal(res[i], res[j])) {
                    j++;
                }
                resclear.push_back(res[i]);
                i = j;
            }
        }
    }

    for (int i = 0; i < resclear.size(); i++) {
        for (int j = 0; j < resclear[i].size(); j++) {
            printf("%d", resclear[i][j]);
            if (j != resclear[i].size() - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    system("pause");
    return 0;
}

/*
沿用上一题思路即可，由于元素有重复的会导致子集有重复，而排序完毕后相同的子集都是相邻的，故可以再次遍历去重，可以尝试一下会不会超时
好，看起来不会超时
*/