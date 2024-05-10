#include <stdio.h>
#include <algorithm>

using namespace std;

int recursion(int n) {
    if (n == 1) {
        return 1;
    }
    else {
        int maxproduct = 1;
        for (int i = 1; i < n; i++) {
            maxproduct = max(maxproduct, max(recursion(n - i), n - i) * i);
        }
        return maxproduct;
    }
}

int main () {
    int n;
    scanf("%d", &n);
    int res = recursion(n);
    printf("%d", res);
    system("Pause");
    return 0;
}

/*
本题经数学证明，在进行分解时，最大的分解方法为尽量多的3+不超过3个2。如果用这种方法则无需进行递归

递归方法下，需要进入循环，遍历从1到n-1
对于每个i，计算两个值：一个是递归计算n-i的最大乘积；另一个是n-i本身的值
比较以上这两个值，取较大的那个，这是计算完了上一步的尽量大的乘积
然后将这个值乘以i，得到可能的最大乘积，并与当前的最大乘积比较
*/