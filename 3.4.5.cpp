#include <stdio.h>
#include <iostream>

using namespace std;

int main () {
    int yy1, yy2, mm1, mm2, dd1, dd2;
    scanf("%d-%d-%d", &yy1, &mm1, &dd1);
    scanf("%d-%d-%d", &yy2, &mm2, &dd2);
    if ((yy1 < yy2) || ((yy1 == yy2) && (mm1 < mm2)) || ((yy1 == yy2) && (mm1 == mm2) && (dd1 < dd2))) {
        printf("YES");
    }
    else {
        printf ("NO");
    }
    return 0;
}

/*
答案直接return比较值确实看起来简单一点
*/