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

void AddOneDay(int& yy, int& mm, int& dd) {
        dd++;
        if (dd > DayofMonth[Isleap(yy)][mm]) {
            dd = 1;
            mm++;
            if (mm > 12) {
                mm = 1;
                yy++;
            }
        }
}

int main () {
    int yy, mm, dd;
    scanf("%d-%d-%d", &yy, &mm, &dd);
    int yyc = 1900;
    int mmc = 1;
    int ddc = 1;
    int week = 1;
    while ((yyc != yy) || (mmc != mm) || (ddc != dd)) {
        AddOneDay(yyc, mmc, ddc);
        week++;
        if (week > 6) {
            week = 0;
        }
    }
    printf ("%d", week);
    return 0;
}

/*
这题要找一个基准点，如果直接找1900年就直接递增即可，用中间的日期可以减少搜索时间但是要判断前后并且引入递增递减
这里以1900年1月1日星期一开始
*/