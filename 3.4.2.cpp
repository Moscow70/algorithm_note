#include <stdio.h>
#include <iostream>

using namespace std;

int DayofMonth[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int Isleap(int yy) {
    if ((yy % 400 == 0) || ((yy % 4 == 0) && (yy % 100 != 0))) {
        return 1;
    }
    else {
        return 0;
    }
}

int main () {
    int yy, mm, dd;
    scanf("%d-%d-%d", &yy, &mm, &dd);
    int n;
    scanf("%d", &n);
    while (n > 0) {
        dd++;
        if (dd > DayofMonth[Isleap(yy)][mm]) {
            dd = 1;
            mm++;
            if (mm > 12) {
                mm = 1;
                yy++;
            }
        }
        n--;
    }
    printf ("%d-%02d-%02d", yy, mm, dd);
    return 0;
}

/*
题解思路：不要一次性加这么多天，一天一天加，需要变化年月时再判断
*/