#include <stdio.h>
#include <algorithm>

using namespace std;

int recursion(int n, int bound) {
    if (n <=0 || bound <= 1) {
        return 0;
    }
    else {
        int ans = 0;
        for (int i = 1; i <= bound; i++) {
            ans = ans + recursion(n - i, i);
            if (n - i > 0 && n - i <= i && n - i < bound) {
                ans++;
            }
        }
        return ans;
    }
}

int main () {
    int n;
    scanf("%d", &n);
    int res = recursion(n, n - 1);
    printf("%d", res);
    system("pause");
    return 0;
}

/*
本题需要限制最大能拆分的数字大小来解决拆分结果重复的问题
所以需要用f(n, bound)来进行递归
1.若n<=1或bound<=0，则不存在拆分方案
2.对每个可能拆分整数i(从1到bound)，函数将尝试将n拆分为i加上对n-i的拆分，因此调用f(n - i, i)
3.如果n-i是一个正数且不超过i，即方案可行，则增加一个方案
*/