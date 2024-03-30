#include <stdio.h>
#include <iostream>

using namespace std;

void countmoney (int& gp, int& sp, int& kp, int& ga, int& sa, int& ka, int& gc, int& sc, int& kc){
    if (ka - kp >= 0) {
        kc = ka - kp;
    }
    else {
        kc = ka + 29 - kp;
        sa--;
    }
    if (sa - sp >= 0) {
        sc = sa - sp;
    }
    else {
        sc = sa + 17 - sp;
        ga--;
    }
    gc = ga - gp;
}

void swap(int& a, int& b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main () {
    int gp, sp, kp;
    int ga, sa, ka;
    scanf("%d.%d.%d %d.%d.%d", &gp, &sp, &kp, &ga, &sa, &ka);
    int gc, sc, kc;
    if ((ga > gp) || ((ga == gp) && (sa > sp)) || ((ga == gp) && (sa == sp) && (ka >= kp))) {
        countmoney(gp, sp, kp, ga, sa, ka, gc, sc, kc);
        printf("%d.%d.%d", gc, sc, kc);
    }
    else {
        swap(ga, gp);
        swap(sa, sp);
        swap(ka, kp);
        countmoney(gp, sp, kp, ga, sa, ka, gc, sc, kc);
        printf("-%d.%d.%d", gc, sc, kc);
    }
    return 0;
}

/*
这题正确思路应该是换算成最小单位，算出差值后再一步步除模来换算成答案，一个一个计算有点麻烦，要考虑的情况太多
*/