#include <stdio.h>
#include <iostream>

using namespace std;

int recursion(int n) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return 1;
    }
    return recursion(n - 1) * n;
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
没坑，过
*/