#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// void recursion (int n) {
//     if (n == 1) {
//         printf("A->C\n");
//     }
//     else {
//         printf("A->B\n");
//         recursion(n - 1);
//         printf("B->C\n");
//     }
// }

void recursion (int n, char from, char to, char mid) {
    if (n == 0) {
        return;
    }
    else {
        recursion (n - 1, from, mid, to);
        printf("%c->%c\n", from, to);
        recursion (n - 1, mid, to, from);
    }
}

int main () {
    int n;
    scanf("%d", &n);
    int sum = (int)pow(2.0, 1.0 * n) - 1;
    printf("%d\n", sum);
    recursion(n, 'A', 'C', 'B');
    system("pause");
    return 0;
}

/*
看起来汉诺塔问题的解答完全不像我想的那样，我这里的思路是把最上面的移到B，再将下面所有的移到C，再将最小的移到C
问题在于，这样的做法意思是最上面这个最小的会始终占用B，而这样根本无法移动别的部分

所以答案应该首先要考虑三根柱子，也即要体现中转的这一环，其次，应该考虑最大的盘子而非最小的盘子，因为最大的盘子必然只能有一种移动方式
*/