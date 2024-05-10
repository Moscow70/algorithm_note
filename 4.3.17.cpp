#include <stdio.h>
#include <algorithm>

using namespace std;

int recursion(int n, int depth) {
    printf("%d\n", depth);
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
    system("pause");
    return 0;

}

/*
递归中，我觉得参数可以大致分为三种，一种是递归自己的局部变量，直接声明使用即可；
另一种是需要随着函数传下去，但值仍需要保持本层递归的值，则需要在参数列表中传下去
第三种是全局变量，可以直接用来记录结果
*/