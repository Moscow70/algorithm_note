#include <stdio.h>
#include <algorithm>

using namespace std;

int recursion(int n, int depth) {
    for (int i = 1; i < depth; i++) {
        printf("    ");
    }
    printf("n=%d\n", n);
    if (n <= 2) {
        return 1;
    }
    else {
        return recursion(n - 1, depth + 1) + recursion(n - 2, depth + 1);
    }
}

int main () {
    int n;
    scanf("%d", &n);
    int res = recursion(n, 1);
    system("Pause");
    return 0;
}

/*
这题跟上一题一样的
*/