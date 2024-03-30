#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    double coe1[1010] = {0};
    double coe2[1010] = {0};
    int n1, n2;
    int maxexp1, maxexp2;
    int i = 0;
    int cnt;
    double co;
    scanf("%d", &n1);
    while (i < n1) {
        scanf("%d", &cnt);
        scanf("%lf", &co);
        coe1[cnt] = co;
        if (i == 0) {
            maxexp1 = cnt;
        }
        i++;

    }
    i = 0;
    scanf("%d", &n2);
    while (i < n2) {
        scanf("%d", &cnt);
        scanf("%lf", &co);
        coe2[cnt] = co;
        if (i == 0) {
            maxexp2 = cnt;
        }
        i++;
    }
    double res[2020] = {0};
    //对一个式子的某一项，循环去乘另一个式子的每一项，直接与本式子的其它项相加
    int nowexp = maxexp1;
    int calexp = maxexp2;
    while (nowexp >=0) {
        while (calexp >= 0) {
            res[nowexp + calexp] = res[nowexp + calexp] + coe1[nowexp] * coe2[calexp];
            calexp--;
        }
        nowexp--;
        calexp = maxexp2;
    }
    i = 0;
    int count = 0;
    int maxexp = maxexp1 + maxexp2;
    while (i <= maxexp) {
        if(res[i] != 0) {
            count++;
        }
        i++;
    }
    i = maxexp;
    printf("%d", count);
    while (i >= 0) {
        if (count == 0) {
            break;
        }
        if (res[i] != 0) {
            printf(" ");
            printf("%d %.1lf", i, res[i]);
        }
        i--;
    }
    return 0;
}

/*优化：
没有必要开两个数组存多项式，可以读完一个另一个边读边算
*/