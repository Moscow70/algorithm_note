#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int recursion(int n) {
    if (n == 1) {
        return 1;
    }
    else if (n == 2) {
        return 1;
    }
    else {
        return recursion(n - 1) + recursion(n - 2);
    }
}

int main () {
    int n;
    scanf("%d", &n);
    int res;
    res = recursion(n);
    printf("%d", res);
    system("pause");
    return 0;
}

/*
没坑，跳
*/