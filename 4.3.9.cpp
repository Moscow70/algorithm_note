#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int recursion(int n) {
    if (n == 1) {
        return 1;
    }
    else if (n == 2) {
        return 2;
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
这题没搞清关系式，到达第n层的方式就是可以先到它前一层或者前两层，两个相加即可
*/