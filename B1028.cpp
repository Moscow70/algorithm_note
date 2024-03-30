#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cstring>

using namespace std;

typedef struct people_info {
    char name[10];
    int y;
    int m;
    int d;
}info;

int main () {
    int n;
    scanf("%d", &n);
    string temp;
    info young = {"", 1814, 9, 6};
    info old = {"", 2014, 9, 6};
    info t = {"", 0, 0, 0};
    int count = 0;
    for (int i = 0; i < n; i++) {
        scanf("%s %d/%d/%d", t.name, &t.y, &t.m, &t.d);
        if (((t.y > 1814) && (t.y < 2014))|| (t.y == 1814 && t.m > 9) || (t.y == 1814 && t.m == 9 && t.d >= 6) || (t.y == 2014 && t.m < 9) || (t.y == 2014 && t.m == 9 && t.d <=6)) {
            if ((t.y < old.y) || (t.y == old.y && t.m < old.m) || (t.y == old.y && t.m == old.m && t.d < old.d)) {
                old = t;
            }
            if ((t.y > young.y) || (t.y == young.y && t.m > young.m) || (t.y == young.y && t.m == young.m && t.d > young.d)) {
                young = t;
            }
            count++;
        }

    }
    if (count != 0) {
        printf ("%d %s %s", count, old.name, young.name);
    }
    else {
        printf("%d", count);
    }
    return 0;
}

/*
年份比较这种比较复杂的东西可以另写一个函数

*/