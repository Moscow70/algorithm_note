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
    int total = dd;
    while (mm > 0) {
        mm--;
        total += DayofMonth[Isleap(yy)][mm];
    }
    printf ("%d", total);
    return 0;
}

/*
这题也差不多照搬上题思路即可
*/