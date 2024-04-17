#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> num;

int maxi(int i) {
    if (i == 0) {
        return num[0];
    }
    else {
        return max(maxi(i - 1), num[i]);//这里用三目运算符居然会超时
    }
}

int main () {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        num.push_back(temp);
    }
    int res;
    res = maxi(n - 1);
    cout << res;
    return 0;
}

/*
不太有思路

递归函数为到坐标i为止的最大值。而由于i为下标，最大的下标即为i-1，要注意细节
*/