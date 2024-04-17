#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

void recursion (int n) {
    if (n == 0) {
        cout << "我的小鲤鱼";
    }
    else {
        cout << "抱着";
        recursion(n - 1);
        cout << "的我";
    }
}

int main () {
    int n;
    cin >> n;
    cout << "吓得我抱起了";
    recursion(n);
    system("pause");
    return 0;
}

/*
刚开始熟悉递归，没什么难题
*/